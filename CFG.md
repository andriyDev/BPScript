# Context-Free Grammar

Here I am defining the CFG of the scripting language. This will evolve as more of the scripting language is developed. Ideally, this would be an LL(1) CFG, but I need to learn more to find out how to do that.

## Terminals

* eps - Epsilon. No tokens are read
* id - An identifier
* num - A number
* prim - A primitive type. These are: float, bool  string, int, name, text, byte
* str - A string

For characters like |, if they are meant to be a token, it will be surrounded by quotes

## Common Non-Terminals

```
Value -> id | 'true' | 'false' | str | num
```

## Non-Terminals

```
Class -> id ':'' id Interfaces '{' ClassBody '}'

Interfaces -> eps | '|' id NextInterface
NextInterface -> eps | ',' id NextInterface
ClassBody -> Variable ClassBody | Dispatcher ClassBody | Construction ClassBody | Function ClassBody | Macro ClassBody | CollapsedNodes ClassBody

Variable -> DataType id Properties Initilization

DataType -> StoredType ElementType
StoredType -> prim | id RefType
RefType -> eps | '*' | '&' | '$' | '#'
ElementType -> eps | '[' ']' | '{' '}' | ':' StoredType

Properties -> eps | '<' Property NextProperty '>'
NextProperty -> eps | ',' Property NextProperty
Property -> id PropertyEnding
PropertyEnding -> eps | ':' PropertyValue
PropertyValue -> Value | '{' num ',' num '}'

Initilization -> ';' | '=' InitVal ';'
InitVal -> Value | 'None' | '{' ContainerBody '}'

ContainerBody-> ArrayBody | MapBody

ArrayBody -> Value OptionalValue
OptionalValue -> ',' Value OptionalValue

MapBody -> ValuePair OptionalValuePair
OptionalValuePair -> ',' ValuePair OptionalValuePair
ValuePair -> Value ':' ValuePairEnding
ValuePairEnding -> Value | '{' MapBody '}' | '{' ArrayBody '}'

Dispatcher -> 'dispatcher' id '(' OptionalParameters ')' ';'
OptionalParameters -> eps | Parameter
Parameter -> 'ref' DataType id ParameterEnding NextParameter | DataType id ParameterEnding NextParameter
ParameterEnding -> eps | '=' Value
NextParameter -> eps | ',' Parameter

Defaults -> 'defaults' '{' VarDefault '}'
VarDefault -> id '=' VarDefaultValue ';'
VarDefaultValue -> Value | '{' MapBody '}' | '{' ArrayBody '}'

Construction -> 'construction' '{' ExecBody '}'

Event -> 'event' ':' id id Properties '(' OptionalParameters ')' '{' ExecBody '}'

Function -> 'function' id Properties '(' OptionalParameters ')' OptionalReturnValues '{' ExecBody '}'
OptionalReturnValues -> eps | ':' DataType id NextReturnValue
NextReturnValue -> eps | ',' DataType id NextReturnValue

Macro -> 'macro' id Properties '(' MacroOptionalParams ')' MacroOptionalReturnValues MacroBodies
MacroOptionalParams -> eps | MacroParam
MacroParam -> 'ref' DataType id ParamaterEnding MacroNextParam | DataType id ParamaterEnding MacroNextParam | Exec id MacroNextParam
MacroNextParam -> eps | ',' MacroParam
MacroOptionalReturnValues -> eps | ':' MacroRetVal MacroNextRetVal
MacroRetVal -> DataType id | 'Exec' id
MacroNextRetVal -> eps | ',' MacroRetVal MacroNextRetVal
MacroBodies -> '{' ExecBody '}' MacroBodiesSansExecute : id '{' ExecBody '}' MacroBodies
MacroBodiesSansExecute -> id '{' ExecBody '}' MacroBodiesSansExecute

CollapsedNodes -> 'collapsed' ':' id id Properties '(' MacroOptionalParams ')' MacroOptionalReturnValues MacroBodies

ExecBody -> eps | Statements
Statements -> Statement Statements

Statement -> NamedPin | FunctionCall | IfStatement | ForLoop | ForBreakLoop | ForEachLoop | ForEachBreakLoop | WhileLoop | WhileBreakLoop | BreakStatement | ReturnStatement | EndStatement | LocalVar

NamedPin -> PinNames '=' Expression ';'

PinNames -> Pin NextPin
NextPin -> eps | ',' Pin NextPin
Pin -> id | id ':' id

// Expression associativity might now work...
Expression -> ExpressionA '&&' Expression | ExpressionA '||' Expression | ExpressionA
ExpressionA -> Expression0 '==' ExpressionA | Expression0
Expression0 -> Expression1 '+' Expression0 | Expression1 '-' Expression0 | Expression1
Expression1 -> Expression2 '*' Expression1 | Expression2 '/' Expression1 | Expression2 '%' Expression1 | Expression2
Expression2 -> Expression3 '^' Expression2 | Expression3
Expression3 -> Expression4 '.' Expression3 | Expression4 '[' Expression ']' | ExpressionFunctionCall | Expression4
Expression4 -> '(' Expression ')' | Value

ExpressionFunctionCall -> id '(' EFCParams ')' EFCRetVal

EFCParams -> eps | EFCParam EFCNextParam
EFCParam -> Expression | id ':' Expression
EFCNextParam -> eps | ',' EFCParam

EFCRetVal -> eps | ':' id

FunctionCall -> id '(' CallParams ')' FunctionCallEnding
CallParams -> eps | Pin CallNextParam
CallNextParam -> eps | ',' Pin CallNextParam
FunctionCallEnding -> ';' | id '{' ExecBody '}' FCBody | '{' ExecBody '}' FCBodySansUnnamed
FCBody -> eps | id '{' ExecBody '}' FCBody | '{' ExecBody '}' FCBodySansUnnamed
FCBodySansUnnamed -> eps | id '{' ExecBody '}' FCBodySansUnnamed

IfStatement -> 'if' '(' Expression ')' '{' ExecBody '}' OptionalElse
OptionalElse -> eps | 'else' '{' ExecBody '}' | 'else' IfStatement

ForLoop -> 'for' id '|' '[' Expression ',' Expression ']' '{' ExecBody '}'
ForBreakLoop -> 'for' ':' BreakName id '|' '[' Expression ',' Expression ']' '{' ExecBody '}'
ForEachLoop -> 'foreach' id '|' '[' Expression ',' Expression ']' '{' ExecBody '}'
ForEachBreakLoop -> 'foreach' ':' BreakName id '|' '[' Expression ',' Expression ']' '{' ExecBody '}'

WhileLoop -> 'while' '(' Expression ')' '{' ExecBody '}'
WhileBreakLoop -> 'while' ':' BreakName '(' Expression ')' '{' ExecBody '}'

BreakName -> eps | id

BreakStatement -> 'break' ';'

ReturnStatement -> 'return' EFCParams ';'

EndStatement -> 'end' OptionalEndExec ';'
OptionalEndExec -> eps | id

LocalVar -> 'local' DataType id OptionalInit ';'
OptionalInit -> eps | '=' Expression
```