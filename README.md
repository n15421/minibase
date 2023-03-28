# hooker

English | [简体中文](README_ZH.md)

This HOOK framework is for ``Bedrock Dedicated Server``, based on ``MinHook`` for secondary API packaging .
Simplifies the development process and improves development efficiency.

## Usage
directly to the project ``include/hooker``, ``src/hooker`` folder and ``lib/minhook.x64d.lib`` add to your project and include ``include/hooker/hook.h`` can be used

## Example
The sample code is located in ``src/dllmain.c`` and ``src/hooks.c`` and currently implements the following functions:
1. output messages like protocol version when the server is started
2. listen to console input and output and print messages
3. disable lava flow by listening to the liquid flow function
4. display the damage generated when a player attacks and send a sound packet to them to make them hear the sound of thunder
5. Play NBS music on a loop after a player enters the server
