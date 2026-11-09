# cpp-practice

大二数据结构 & 蓝桥杯刷题的 C++ 练习仓库。

## 环境

- 编译器：MSVC 19.44（随 Visual Studio 2022 安装，静态链接 `/MT`，生成的 exe 可直接拷走运行）
- 编辑器：VS Code + C/C++ 扩展
- 标准：C++17

## 怎么用

1. 用 VS Code 打开这个文件夹（`文件 → 打开文件夹`）
2. 新建或选中一个 `.cpp` 文件
3. **Ctrl + Shift + B** 编译 → 生成 `build/<文件名>.exe`
4. 终端里执行 `.\build\hello.exe` 运行
5. 按 **F5** 可断点调试（会自动先编译）

也可以在终端里手动编译：

```bat
build.bat hello.cpp
```

## 目录约定

```
cpp-practice/
├── .vscode/          配置文件（编译任务、调试、智能提示）
├── build/            编译产物（exe / obj / pdb，不提交到 git）
├── build.bat         一键编译脚本
├── hello.cpp         环境验证程序
└── 你的练习文件.cpp
```

## 注意

- 源码统一用 **UTF-8** 编码保存，编译时已加 `/utf-8`，中文注释和输出不会乱码
- 终端建议用 VS Code 默认的 `PowerShell (UTF-8)` 配置（已在 settings.json 里设置）
- 如果哪天升级了 VS2022 或 Windows SDK，`build.bat` 会自动找最新的版本目录，不需要改脚本
