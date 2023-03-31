# hooker

[![wakatime](https://wakatime.com/badge/user/2838d0e1-1416-4f45-bc46-cbda8f4d9e75/project/93f45b7b-afeb-4f15-a5cd-6fabd00b17c9.svg)](https://wakatime.com/badge/user/2838d0e1-1416-4f45-bc46-cbda8f4d9e75/project/93f45b7b-afeb-4f15-a5cd-6fabd00b17c9)

[![CodeFactor](https://www.codefactor.io/repository/github/willowsaucer/hooker/badge)](https://www.codefactor.io/repository/github/willowsaucer/hooker)

[English](README.md) | 简体中文

本项目是针对``Bedrock Dedicated Server``而编写的HOOK框架，基于``MinHook``进行二次API包装。
简化了开发流程，提高了开发效率。

## 用法
直接将本项目的``include/hooker``，``src/hooker``文件夹以及``lib/minhook.x64d.lib``添加到你的项目中，并包含``include/hooker/hook.h``即可使用

## 示例
示例代码位于``src/dllmain.c``和``src/hooks.c``，目前实现的功能如下：
1. 开服时输出消息，如协议版本号
2. 监听控制台输入输出并打印消息
3. 通过监听液体流动函数来禁止岩浆流动
4. 在玩家攻击时显示产生的伤害并向其发送声音包，使其听到雷声
5. 在玩家进入服务器后循环播放NBS音乐

## 许可证

| 项目                                                         | 许可证                                                                   |
| ------------------------------------------------------------ | ----------------------------------------------------------------------- |
| [minhook](https://github.com/TsudaKageyu/minhook)            | [许可证](https://github.com/TsudaKageyu/minhook/blob/master/LICENSE.txt) |
| [uthash](https://github.com/troydhanson/uthash)              | [许可证](https://github.com/troydhanson/uthash/blob/master/LICENSE)      |
| [microsoft-pdb](https://github.com/microsoft/microsoft-pdb/) | [许可证](https://github.com/microsoft/microsoft-pdb/blob/master/LICENSE) |
