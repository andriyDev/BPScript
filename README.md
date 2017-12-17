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

## Progress

The lexical analyzer is "done". It works, although it may need to be modified to get better. It currently is very restricted and context specific. It may be better to use Regex, but for now, it works.

Currently working on the parser. I need to make a finished version of the script so I have an example to go off of. I've started the context-free grammar. It can be found in CFG.md
