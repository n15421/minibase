# hooker
本项目是针对``Bedrock Dedicated Server``而编写的HOOK框架，基于``MinHook进``行二次API包装。
简化了开发流程，提高了开发效率。

## Usage
直接将本项目的``include/hooker``，``src/hooker``文件夹以及``lib/minhook.x64d.lib``添加到你的项目中，并包含``include/hooker/hook.h``即可使用

## Example
示例代码位于``src/dllmain.c``和``src/hooks.c``，目前实现的功能如下：
1. 开服时输出消息
2. 监听控制台输入输出并打印消息
3. 通过监听液体流动函数来禁止岩浆流动
