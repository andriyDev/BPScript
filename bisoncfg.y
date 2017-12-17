// Prologue
%{
	#define _GNU_SOURCE
	#include <stdio.h>
	#include "ptypes.h"
%}

%union {
  long int n;
  tree t;  /* tree is defined in ptypes.h. */
}
%{
  static void print_token_value (FILE *, int, YYSTYPE);
  #define YYPRINT(F, N, L) print_token_value (F, N, L)
%}

// Bison declarations
%token ID
%token NUM
%token PRIM
%token STR


// Grammar Rules
%%
Class: id ':' id Interfaces '{' ClassBody '}';

Interfaces: %empty | '|' id NextInterface;
NextInterface: %empty | ',' id NextInterface;
ClassBody: Variable ClassBody | Dispatcher ClassBody | Construction ClassBody | Function ClassBody | Macro ClassBody | CollapsedNodes ClassBody;

Variable: DataType id Properties Initilization;

DataType: StoredType ElementType;
StoredType: prim | id RefType;
RefType: %empty | '*' | '&' | '$' | '#';
ElementType: %empty | '[' ']' | '{' '}' | ':' StoredType;

Properties: %empty | '<' Property NextProperty '>';
NextProperty: %empty | ',' Property NextProperty;
Property: id PropertyEnding;
PropertyEnding: %empty | ':' PropertyValue;
PropertyValue: Value | '{' num ',' num '}';

Initilization: ';' | '=' InitVal ';';
InitVal: Value | 'None' | '{' ContainerBody '}';

ContainerBody-> ArrayBody | MapBody;

ArrayBody: Value OptionalValue;
OptionalValue: ',' Value OptionalValue;

MapBody: ValuePair OptionalValuePair;
OptionalValuePair: ',' ValuePair OptionalValuePair;
ValuePair: Value ':' ValuePairEnding;
ValuePairEnding: Value | '{' MapBody '}' | '{' ArrayBody '}';

Dispatcher: 'dispatcher' id '(' OptionalParameters ')' ';';
OptionalParameters: %empty | Parameter;
Parameter: 'ref' DataType id ParameterEnding NextParameter | DataType id ParameterEnding NextParameter;
ParameterEnding: %empty | '=' Value;
NextParameter: %empty | ',' Parameter;

Defaults: 'defaults' '{' VarDefault '}';
VarDefault: id '=' VarDefaultValue ';';
VarDefaultValue: Value | '{' MapBody '}' | '{' ArrayBody '}';

Construction: 'construction' '{' ExecBody '}';

Event: 'event' ':' id id Properties '(' OptionalParameters ')' '{' ExecBody '}';

Function: 'function' id Properties '(' OptionalParameters ')' OptionalReturnValues '{' ExecBody '}';
OptionalReturnValues: %empty | ':' DataType id NextReturnValue;
NextReturnValue: %empty | ',' DataType id NextReturnValue;

Macro: 'macro' id Properties '(' MacroOptionalParams ')' MacroOptionalReturnValues MacroBodies;
MacroOptionalParams: %empty | MacroParam;
MacroParam: 'ref' DataType id ParamaterEnding MacroNextParam | DataType id ParamaterEnding MacroNextParam | Exec id MacroNextParam;
MacroNextParam: %empty | ',' MacroParam;
MacroOptionalReturnValues: %empty | ':' MacroRetVal MacroNextRetVal;
MacroRetVal: DataType id | 'Exec' id;
MacroNextRetVal: %empty | ',' MacroRetVal MacroNextRetVal;
MacroBodies: '{' ExecBody '}' MacroBodiesSansExecute : id '{' ExecBody '}' MacroBodies;
MacroBodiesSansExecute: id '{' ExecBody '}' MacroBodiesSansExecute;

CollapsedNodes: 'collapsed' ':' id id Properties '(' MacroOptionalParams ')' MacroOptionalReturnValues MacroBodies;

ExecBody: %empty | Statements;
Statements: Statement Statements;

Statement: NamedPin | FunctionCall | IfStatement | ForLoop | ForBreakLoop | ForEachLoop | ForEachBreakLoop | WhileLoop | WhileBreakLoop | BreakStatement | ReturnStatement | EndStatement | LocalVar;

NamedPin: PinNames '=' Expression ';';

PinNames: Pin NextPin;
NextPin: %empty | ',' Pin NextPin;
Pin: id | id ':' id;

Expression: Expression '&&' ExpressionB | Expression '||' ExpressionB | ExpressionB;
ExpressionB: ExpressionB '>' ExpressionA | ExpressionB '<' ExpressionA | ExpressionB '>=' ExpressionA | ExpressionB '<=' ExpressionA | ExpressionA;
ExpressionA: ExpressionA '==' Expression0 | ExpressionA '!=' Expression0 | Expression0;
Expression0: Expression0 '+' Expression1 | Expression0 '-' Expression1 | Expression1;
Expression1: Expression1 '*' Expression2 | Expression1 '/' Expression2 | Expression1 '%' Expression2 | Expression2;
Expression2: Expression2 '^' Expression3 | Expression3
Expression3: Expression3 '.' Expression4 | Expression3 '[' Expression ']' | ExpressionFunctionCall | Expression4;
Expression4: '(' Expression ')' | Value;

ExpressionFunctionCall: id '(' EFCParams ')' EFCRetVal;

EFCParams: %empty | EFCParam EFCNextParam;
EFCParam: Expression | id ':' Expression;
EFCNextParam: %empty | ',' EFCParam;

EFCRetVal: %empty | ':' id;

FunctionCall: id '(' CallParams ')' FunctionCallEnding;
CallParams: %empty | Pin CallNextParam;
CallNextParam: %empty | ',' Pin CallNextParam;
FunctionCallEnding: ';' | id '{' ExecBody '}' FCBody | '{' ExecBody '}' FCBodySansUnnamed;
FCBody: %empty | id '{' ExecBody '}' FCBody | '{' ExecBody '}' FCBodySansUnnamed;
FCBodySansUnnamed: %empty | id '{' ExecBody '}' FCBodySansUnnamed;

IfStatement: 'if' '(' Expression ')' '{' ExecBody '}' OptionalElse;
OptionalElse: %empty | 'else' '{' ExecBody '}' | 'else' IfStatement;

ForLoop: 'for' id '|' '[' Expression ',' Expression ']' '{' ExecBody '}';
ForBreakLoop: 'for' ':' BreakName id '|' '[' Expression ',' Expression ']' '{' ExecBody '}';
ForEachLoop: 'foreach' id '|' '[' Expression ',' Expression ']' '{' ExecBody '}';
ForEachBreakLoop: 'foreach' ':' BreakName id '|' '[' Expression ',' Expression ']' '{' ExecBody '}';

WhileLoop: 'while' '(' Expression ')' '{' ExecBody '}';
WhileBreakLoop: 'while' ':' BreakName '(' Expression ')' '{' ExecBody '}';

BreakName: %empty | id;

BreakStatement: 'break' ';';

ReturnStatement: 'return' EFCParams ';';

EndStatement: 'end' OptionalEndExec ';';
OptionalEndExec: %empty | id;

LocalVar: 'local' DataType id OptionalInit ';';
OptionalInit: %empty | '=' Expression;
%%

// Epilogue

