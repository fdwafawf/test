# Heads-Up Display (HUD) - 系统监控桌面悬浮窗

## 项目简介

这是一个基于 Qt5 和 C++ 开发的桌面系统监控悬浮窗应用程序。它可以实时显示 CPU 使用率和内存使用情况，并以透明的悬浮窗形式显示在桌面最上层，方便用户随时监控系统性能。

## 主要特性

- **实时监控**：每秒更新一次 CPU 使用率和内存使用情况
- **悬浮显示**：窗口始终保持在其他应用程序之上，不会被遮挡
- **半透明界面**：黑色半透明背景，不影响桌面美观
- **无边框设计**：采用圆角矩形设计，界面简洁美观
- **可拖动**：支持鼠标左键拖动窗口到任意位置
- **CPU 预警**：当 CPU 使用率超过 80% 时，显示红色警告指示灯
- **右键菜单**：右键点击可快速退出应用程序

## 技术栈

- **开发语言**：C++11
- **UI 框架**：Qt5 (Qt Widgets)
- **构建工具**：CMake 3.10+
- **平台支持**：Windows（使用 Windows API 获取系统信息）

## 项目结构

```
headsUpDisplay/
├── CMakeLists.txt           # CMake 构建配置文件
├── src/
│   ├── main.cpp            # 程序入口
│   ├── headsUpDisplay.h    # 主窗口头文件
│   ├── headsUpDisplay.cpp  # 主窗口实现（UI 逻辑）
│   ├── headsUpDisplay.ui   # Qt Designer UI 文件
│   ├── systemMonitor.h     # 系统监控类头文件
│   └── systemMonitor.cpp   # 系统监控实现（CPU/内存获取）
└── build/                  # 构建输出目录
```

## 核心功能说明

### 系统监控 (systemMonitor)

- **getCpuUsage()**：获取 CPU 使用率（百分比）
  - 使用 Windows API `GetSystemTimes()` 获取系统时间
  - 计算相邻两次采样之间的 CPU 空闲时间和总时间差值
  - 返回 CPU 占用百分比

- **getMemoryUsage()**：获取内存使用率（百分比）
  - 使用 Windows API `GlobalMemoryStatusEx()` 获取内存状态

- **getMemoryStr()**：获取内存使用情况字符串（已用/总计 GB）
  - 计算已用内存和总内存
  - 返回格式化的字符串，如 "8.5 / 16.0 GB"

### 界面显示 (headsUpDisplay)

- **无边框透明窗口**：使用 Qt 窗口标志实现悬浮效果
- **自定义绘制**：重写 `paintEvent()` 方法，使用 QPainter 绘制界面
- **定时刷新**：使用 QTimer 每秒触发一次数据更新和界面重绘
- **鼠标交互**：支持拖动和右键菜单

## 构建说明

### 环境要求

- CMake 3.10 或更高版本
- Qt 5.12+ (推荐 Qt 5.14.2 或更高版本)
- MinGW 或 MSVC 编译器（Windows）

### 构建步骤

1. 修改 `CMakeLists.txt` 中的 Qt 路径：
   ```cmake
   set(CMAKE_PREFIX_PATH "你的Qt安装路径/5.14.2/mingw73_64") # 例如: "C:/Qt/5.14.2/mingw73_64"
   ```

2. 创建构建目录并编译：
   ```bash
   cd headsUpDisplay
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

3. 运行程序：
   ```bash
   ./headsUpDisplay.exe
   ```

## 使用方法

1. 启动应用程序后，会在桌面上显示一个半透明的悬浮窗
2. 悬浮窗会实时显示 CPU 使用率和内存使用情况
3. 用鼠标左键可以拖动窗口到任意位置
4. 右键点击窗口，选择"退出"可以关闭应用程序
5. 当 CPU 使用率超过 80% 时，窗口右上角会显示红色警告圆点

## 扩展建议

- 添加网络流量监控
- 支持 GPU 使用率显示
- 可配置的刷新频率和预警阈值
- 支持多种主题和外观定制
- 跨平台支持（Linux、macOS）

## 许可证

本项目为测试项目。

---

**注意**：本应用程序目前仅支持 Windows 平台，因为使用了 Windows 特有的 API 来获取系统信息。
