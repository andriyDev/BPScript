# BPScript

This is a scripting language for the Unreal Engine to write Blueprints in text. This comes from the fact that the C++ compilation takes way too long (often around 30 seconds, sometimes longer). Blueprints are much faster to compile, but also are bad due to all the dragging and mis-clicking that can happen. Also, as a programmer, typing can be a lot faster and organization can be significantly better.

Currently, the compiler is implemented as a commandlet. I hope to integrate this in the editor at some point. I'm still learning how to write a compiler, so improvements will be made as I progress.

An example of a blueprint in script form can be found in TestBP.bp.

## Compiling a script

To compile a script, run the following command:

```
UE4Editor-Cmd.exe "<PATH_TO_YOUR_UPROJECT>" -run=BPScript "<PATH_TO_YOUR_SCRIPT>"
```

Currently, it just outputs a visualization of the blueprint in the console.

## Language

This will be a tutorial of sorts for the language.

### Classes

To create a new class (e.g. Tree), start with the following template:

```
Tree : Actor
{

}
```

This is the most basic class. Notice that the parent class (e.g. Actor) is required. To add interfaces, add after the parent name:

```
Tree : Actor | Punchable, Growable, ...
{

}
```

### Variables

Adding variables can be done inside the braces of a class:

```
float GrowthPercent;
```

For structs (such as Vector or Rotator), you just put the identifier of the struct:

```
Vector OptimalSunDirection;
```

For objects, there are 4 reference types (a reference type is required for objects):

```
Material* LeafMaterial; // This is an Object Reference
Actor& SaplingClass; // This is a Class Reference
CustomClass$ SomethingSpecial; // This is a Soft Object Reference
CustomClass# SomethingSpecialerClass; // This is a Soft Class Reference
```

Variables can also be arrays, sets, or maps:

```
float[] RootWaterAmount; // An array of floats
Actor*{} Acorns; // A set of Actor object references
name:Actor CloudsByName; // A map with Names for keys and Actors for values
```

Following the variable name can be a set of properties:

```
float GrowthPercent<InstanceEditable, ExposeOnSpawn>;
```

Some properties require values:

```
float GrowthPercent<Replication: Replicated, Tooltip: "The amount the tree has grown", Private: false, ValueRange: {0, 1}>;
```

No value evaluates to "true". Finally, following the properties is the initialization:

```
float GrowthPercent = 0.3;
int[] SeedsPerSeason = {10, 7, 3, 0};
Vector SunDirection = { X: 0.1, Y: 0.1, Z: 0.99 };
name:Vector CloudVelocities = { "Orion": { X: 0, Y: 0, Z: 0 } };
int{} RootNumbers = {3, 2, 6, 1};
```

Notice that structs and dictionaries have the same notation, which can be nested.

### Event Dispatchers

Event dispatchers (e.g. OnTreeGrown) are defined inside a class body as:

```
dispatcher OnTreeGrown();
```

Parameters may be provided. They are a data type with an identifier, just like variables (excluding properties).

```
dispatcher OnTreeGrown(float Height, Actor* GrownTree);
```

Adding ref in front of a parameter will make it a reference:

```
dispatcher OnTreeGrown(ref float Height, Actor* GrownTree);
```

For primitive types, parameters may have a default value:

```
dispatcher OnTreeGrown(float Height = 7.3, string message = "What is this? A tree for ants???");
```

### Defaults

Setting defaults for variables created in the script is easy. However, for other variables, you must use the defaults section. It used included in the class body:

```
defaults
{
	StartWithTickEnabled = true;
	TickInterval = 10;
	SpawnCollisionHandling = TryToAdjustLocationDontSpawnIfStillColliding;
}
```

You can also set arrays this way, or what have you. These must follow the same format as initializing a variable for a defined variable (above).

### Construction Script

To write code for the construction script, use the following:

```
construction
{
	// Code goes here.
}
```

We will cover how to fill this below.

### Events

To write events, use the following:

```
event Tick(float DeltaSeconds)
{
	// Code goes here
}
```

The parameters follow the same pattern as the event dispatchers. Events can also have properties. These follow the same format as variables:

```
event MyCustomEvent<Replicates: Multicast, ReplicatesReliable>(int Param1 = 3, ref Actor* Param2)
{
	// Code goes here
}
```

We will cover how to fill this below.

### Functions

Functions have the following form:

```
function TestFunc()
{
	// Code goes here
}
```

Pure functions have similar form:

```
pure TestFunct()
{
	// Code goes here
}
```

Parameters have the same pattern as event dispatchers. Functions may also have return values. These can be specified as:

```
function TestFunc() : Vector Dir, float Len
{
	// Code goes here
}
```

Return values also follow the same pattern as the parameters of event dispatchers with the exception that they cannot use ref or have default values.

We will cover how to fill this below.

### Macros and Collapsed Nodes

Macros and Collapsed Nodes are functionally identically, so I will combine them here. The only difference between the two is the following:

```
collapsed AThingy()
{
	// Code goes here
}

macro AThingy()
{
	// Code goes here
}
```

I will use macros here, but they will be the same except for the initial keyword.

Macros have the same parameter format as event dispatchers, with the exception that macros have a new variable type: Exec:

```
macro TestMacro(Exec A1, float aValueThingy, Exec A2)
A1 {
	// Code goes here
}
A2 {
	// Code goes here
}
```

Notice for each Exec parameter, there is a corresponding named block. The exception is for an Exec named execute:

```
macro TestMacro(Exec execute, float aValueThingy, Exec A2)
{
	// Code goes here
}
A2 {
	// Code goes here
}
```

Here, the first block is unnamed. This way, macros with only one Exec variable can avoid the naming. Macros may also have return values. These are similar to function return values, with the exception that they may have Exec variables.

```
macro TestMacro(Exec A1, Exec A2) : Exec B1, Exec B2, float Value
A1 {
	// Code goes here
}
A2 {
	// Code goes here
}
```

## Progress

The lexical analyzer is "done". It works, although it may need to be modified to get better. It currently is very restricted and context specific. It may be better to use Regex, but for now, it works.

Currently working on the parser. I need to make a finished version of the script so I have an example to go off of. I've started the context-free grammar. It can be found in CFG.md
