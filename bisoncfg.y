// Prologue
%{
	#define _GNU_SOURCE
%}

// Bison declarations
%token ID
%token NUM
%token PRIM
%token STR

%token TRUE "true"
%token FALSE "false"
%token NONE "None"
%token DISPATCHER "dispatcher"
%token EVENT "event"
%token DEFAULTSKW "defaults"
%token CONSTRUCTION "construction"
%token FUNCTION "function"
%token MACRO "macro"
%token COLLAPSED "collapsed"
%token REF "ref"
%token EXEC "Exec"
%token IF "if"
%token ELSE "else"
%token VAR "var"
%token FOR "for"
%token FOREACH "foreach"
%token WHILE "while"
%token BREAK "break"
%token RETURN "return"
%token END "end"
%token LOCAL "local"

%token LOGAND "&&"
%token LOGOR "||"
%token GTE ">="
%token LTE "<="
%token EQ "=="
%token NEQ "!="

// Grammar Rules
%%

Class: ID ':' ID Interfaces '{' ClassBody '}';

Value: ID | TRUE | FALSE | NONE | STR | NUM

Interfaces: %empty | '|' ID NextInterface;
NextInterface: %empty | ',' ID NextInterface;
ClassBody: %empty | ClassBody Variable | ClassBody Dispatcher | ClassBody Defaults | ClassBody Construction | ClassBody Event | ClassBody Function | ClassBody Macro | ClassBody CollapsedNodes;

Variable: VAR DataType ID Properties Initilization;

DataType: StoredType ElementType;
StoredType: PRIM | ID RefType;
RefType: %empty | '*' | '&' | '$' | '#';
ElementType: %empty | '[' ']' | '{' '}' | ':' StoredType;

Properties: %empty | '<' Property NextProperty '>';
NextProperty: %empty | ',' Property NextProperty;
Property: ID PropertyEnding;
PropertyEnding: %empty | ':' PropertyValue;
PropertyValue: Value | '{' NUM ',' NUM '}';

Initilization: ';' | '=' InitVal ';';
InitVal: Value | '{' ContainerBody '}';

ContainerBody: ArrayBody | MapBody;

ArrayBody: Value OptionalValue;
OptionalValue: %empty | ',' Value OptionalValue;

MapBody: ValuePair OptionalValuePair;
OptionalValuePair: %empty | ',' ValuePair OptionalValuePair;
ValuePair: Value ':' ValuePairEnding;
ValuePairEnding: Value | '{' MapBody '}' | '{' ArrayBody '}';

Dispatcher: DISPATCHER ID '(' OptionalParameters ')' ';';
OptionalParameters: %empty | Parameter;
Parameter: REF DataType ID ParameterEnding NextParameter | DataType ID ParameterEnding NextParameter;
ParameterEnding: %empty | '=' Value;
NextParameter: %empty | ',' Parameter;

Defaults: DEFAULTSKW '{' VarDefault '}';
VarDefault: ID '=' VarDefaultValue ';';
VarDefaultValue: Value | '{' MapBody '}' | '{' ArrayBody '}';

Construction: CONSTRUCTION '{' ExecBody '}';

Event: EVENT ':' ID ID Properties '(' OptionalParameters ')' '{' ExecBody '}';

Function: FUNCTION ID Properties '(' OptionalParameters ')' OptionalReturnValues '{' ExecBody '}';
OptionalReturnValues: %empty | ':' DataType ID NextReturnValue;
NextReturnValue: %empty | ',' DataType ID NextReturnValue;

Macro: MACRO ID Properties '(' MacroOptionalParams ')' MacroOptionalReturnValues MacroBodies;
MacroOptionalParams: %empty | MacroParam;
MacroParam: REF DataType ID ParameterEnding MacroNextParam | DataType ID ParameterEnding MacroNextParam | EXEC ID MacroNextParam;
MacroNextParam: %empty | ',' MacroParam;

MacroOptionalReturnValues: %empty | ':' MacroRetVal MacroNextRetVal;
MacroRetVal: DataType ID | EXEC ID;
MacroNextRetVal: %empty | ',' MacroRetVal MacroNextRetVal;
MacroBodies: MacroBodies MacroBody | %empty;
MacroBody: ID '{' ExecBody '}' | '{' ExecBody '}'

CollapsedNodes: COLLAPSED ':' ID ID Properties '(' MacroOptionalParams ')' MacroOptionalReturnValues MacroBodies;

ExecBody: %empty | ExecBody Statement;

Statement: NamedPin | FunctionCall | IfStatement | ForLoop | ForBreakLoop | ForEachLoop | ForEachBreakLoop | WhileLoop | WhileBreakLoop | BreakStatement | ReturnStatement | EndStatement | LocalVar;

NamedPin: PinNames '=' Expression ';';

PinNames: Pin NextPin;
NextPin: %empty | ',' Pin NextPin;
Pin: ID | ID ':' ID;

Expression: Expression LOGAND ExpressionB | Expression LOGOR ExpressionB | ExpressionB;
ExpressionB: ExpressionB '>' ExpressionA | ExpressionB '<' ExpressionA | ExpressionB GTE ExpressionA | ExpressionB LTE ExpressionA | ExpressionA;
ExpressionA: ExpressionA EQ Expression0 | ExpressionA NEQ Expression0 | Expression0;
Expression0: Expression0 '+' Expression1 | Expression0 '-' Expression1 | Expression1;
Expression1: Expression1 '*' Expression2 | Expression1 '/' Expression2 | Expression1 '%' Expression2 | Expression2;
Expression2: Expression2 '^' Expression3 | Expression3
Expression3: Expression3 '.' Expression4 | Expression3 '[' Expression ']' | ExpressionFunctionCall | Expression4;
Expression4: '(' Expression ')' | Value;

ExpressionFunctionCall: ID '(' EFCParams ')' EFCRetVal;

EFCParams: %empty | EFCParam EFCNextParam;
EFCParam: Expression | ID ':' Expression;
EFCNextParam: %empty | ',' EFCParam;

EFCRetVal: %empty | ':' ID;

FunctionCall: ID '(' CallParams ')' FunctionCallEnding;
CallParams: %empty | Pin CallNextParam;
CallNextParam: %empty | ',' Pin CallNextParam;
FunctionCallEnding: FCBody ';';
FCBody: %empty | FCBody ID '{' ExecBody '}' | FCBody '{' ExecBody '}';

IfStatement: IF '(' Expression ')' '{' ExecBody '}' OptionalElse;
OptionalElse: %empty | ELSE '{' ExecBody '}' | ELSE IfStatement;

ForLoop: FOR ID '|' '[' Expression ',' Expression ']' '{' ExecBody '}';
ForBreakLoop: FOR ':' ID ID '|' '[' Expression ',' Expression ']' '{' ExecBody '}';
ForEachLoop: FOREACH ID '|' '[' Expression ',' Expression ']' '{' ExecBody '}';
ForEachBreakLoop: FOREACH ':' ID ID '|' '[' Expression ',' Expression ']' '{' ExecBody '}';

WhileLoop: WHILE '(' Expression ')' '{' ExecBody '}';
WhileBreakLoop: WHILE ':' ID '(' Expression ')' '{' ExecBody '}';

BreakStatement: BREAK ';';

ReturnStatement: RETURN EFCParams ';';

EndStatement: END OptionalEndExec ';';
OptionalEndExec: %empty | ID;

LocalVar: LOCAL DataType ID OptionalInit ';';
OptionalInit: %empty | '=' Expression;
%%

// Epilogue

