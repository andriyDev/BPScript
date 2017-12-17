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
ClassBody -> Variable ClassBody | Function ClassBody

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
```