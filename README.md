# Qt 信号与槽连接方式演示项目

## 项目简介

本项目是一个 Qt 6 示例项目，旨在演示 Qt 框架中**信号与槽（Signal & Slot）机制**的多种连接方式。通过实际代码展示，帮助开发者理解和掌握 Qt 中信号槽的不同实现方法。

## 技术栈

| 技术 | 版本 | 说明 |
|------|------|------|
| Qt | 6.5+ | 核心框架 |
| CMake | 3.19+ | 构建工具 |
| C++ | C++17 | 编程语言 |
| MinGW | 64-bit | 编译器（Windows） |

## 项目结构

```
HowToConnectSignalAndSlot/
├── main.cpp              # 应用程序入口
├── mywidget.h            # 自定义窗口类头文件
├── mywidget.cpp          # 自定义窗口类实现（核心代码）
├── mywidget.ui           # Qt Designer 界面文件
├── CMakeLists.txt        # CMake 构建配置
├── .clangd               # Clangd 配置文件
├── .qtcreator/           # Qt Creator 项目配置
└── build/                # 构建输出目录
```

## 信号与槽的五种连接方式

本项目展示了 Qt 中信号与槽的五种连接方式，每种方式对应一个按钮操作：

### 1. SIGNAL/SLOT 宏方式（Qt 4 风格）

**特点**：传统的字符串匹配方式，编译期不进行类型检查。

```cpp
// 最大化显示按钮
connect(ui->btnMax, SIGNAL(clicked()), this, SLOT(showMaximized()));
```

**优缺点**：
- ✅ 兼容性好，支持旧版 Qt
- ❌ 编译期不检查，错误运行时才发现
- ❌ 不支持重载函数

---

### 2. 函数指针方式（Qt 5 风格）

**特点**：使用函数地址进行连接，编译期类型安全检查。

```cpp
// 正常显示按钮
connect(ui->btnNormal, &QPushButton::clicked, this, &QWidget::showNormal);
```

**优缺点**：
- ✅ 编译期类型检查，更安全
- ✅ 性能更好
- ❌ 无法直接指定重载函数（需使用 `QOverload`）

---

### 3. Qt Designer 转到槽

**特点**：通过 Qt Designer 自动生成槽函数声明和实现框架。

```cpp
// 最小化显示按钮（自动生成）
void MyWidget::on_btnMin_clicked()
{
    this->showMinimized();
}
```

**命名规则**：`on_<控件名>_<信号名>`

**优缺点**：
- ✅ 简单直观，适合快速开发
- ✅ 自动生成代码框架
- ❌ 槽函数命名受约束

---

### 4. Qt Designer 信号槽编辑器

**特点**：在 Qt Designer 中通过可视化界面配置信号槽连接。

在 `mywidget.ui` 文件中可以看到配置：

```xml
<connections>
  <connection>
    <sender>btnClose</sender>
    <signal>clicked()</signal>
    <receiver>MyWidget</receiver>
    <slot>close()</slot>
  </connection>
</connections>
```

**优缺点**：
- ✅ 无需编写代码，纯可视化配置
- ✅ 适合快速原型开发
- ❌ 复杂逻辑难以处理

---

### 5. Lambda 表达式方式（Qt 5+）

**特点**：使用 C++11 Lambda 表达式作为槽函数，灵活强大。

```cpp
// 修改窗口标题按钮
connect(ui->btnModify, &QPushButton::clicked, this,
        [this]()
        {
            QString title = QDateTime::currentDateTime().toString("yyyy-MM-dd:hh:mm:ss");
            this->setWindowTitle(title);
        });
```

**优缺点**：
- ✅ 代码紧凑，逻辑内联
- ✅ 支持捕获外部变量
- ✅ 适合简单逻辑处理
- ❌ 复杂逻辑可能降低可读性

---

## Lambda 表达式详解

项目中包含了 Lambda 表达式的完整用法演示（已注释）：

| 语法 | 说明 | 示例 |
|------|------|------|
| `[](){}` | 空捕获列表 | `[](){ qDebug() << "lambda"; };` |
| `[](){}()` | 定义后立即调用 | `[](){ qDebug() << "lambda"; }();` |
| `[&]()` | 按引用捕获所有变量 | `[&](){ qDebug() << a++; }();` |
| `[=]()` | 按值捕获所有变量（只读） | `[=](){ qDebug() << a; }();` |
| `[=]() mutable` | 按值捕获 + 可修改 | `[=]()mutable{ qDebug() << a++; }();` |
| `[](int x, int y)` | 带参数 | `[](int x, int y){ qDebug() << x+y; }(1,2);` |
| `[](int x,int y)->int` | 显式返回类型 | `int sum = [](int x,int y)->int{ return x+y; }(1,2);` |

---

## 构建与运行

### 环境要求

- Qt 6.5 或更高版本
- CMake 3.19 或更高版本
- 支持 C++17 的编译器

### 构建步骤

**方法一：使用 Qt Creator**

1. 打开 Qt Creator
2. 选择 `File > Open File or Project...`
3. 选择项目根目录下的 `CMakeLists.txt`
4. 点击 `Configure` 按钮
5. 选择目标构建套件（如 Desktop Qt 6.8.3 MinGW 64-bit）
6. 点击 `Build > Build All`
7. 点击 `Run` 运行项目

**方法二：使用命令行**

```bash
# 创建构建目录
mkdir build && cd build

# 配置 CMake（指定 Qt 路径）
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt/6.x.x/mingw_64

# 构建项目
cmake --build . --config Debug

# 运行
./Debug/HowToConnectSignalAndSlot.exe
```

### 运行效果

程序启动后显示一个窗口，包含五个按钮：

| 按钮 | 功能 | 连接方式 |
|------|------|----------|
| 最大化显示 | 将窗口最大化 | SIGNAL/SLOT 宏 |
| 正常显示 | 恢复窗口正常大小 | 函数指针 |
| 最小化显示 | 将窗口最小化 | Designer 转到槽 |
| 关闭窗口 | 关闭应用程序 | Designer 信号槽编辑器 |
| 修改窗口标题 | 用当前时间设置窗口标题 | Lambda 表达式 |

---

## 核心文件说明

### main.cpp

应用程序入口文件，创建 `QApplication` 和主窗口 `MyWidget`。

### mywidget.h

自定义窗口类头文件，声明槽函数 `on_btnMin_clicked()`。

### mywidget.cpp

核心实现文件，包含五种信号槽连接方式的完整代码示例。

### mywidget.ui

Qt Designer 界面文件，定义了窗口布局和信号槽连接（btnClose）。

### CMakeLists.txt

CMake 构建配置文件，配置了 Qt 依赖和构建目标。

---

## 学习要点

1. **信号槽机制**是 Qt 的核心特性，实现了对象间的解耦通信
2. **推荐使用 Qt 5 风格**（函数指针或 Lambda），更安全高效
3. **Lambda 表达式**适合处理简单的回调逻辑
4. **Qt Designer** 适合快速构建 UI 原型
5. 信号槽连接时需注意**参数类型匹配**和**生命周期管理**

---

## 常见问题

### Q1: SIGNAL/SLOT 宏方式编译通过但运行时无效？

**原因**：字符串拼写错误或参数不匹配，编译期无法检查。

**解决**：改用函数指针方式，编译期会报错提示。

### Q2: 函数指针方式如何处理重载函数？

**解决**：使用 `QOverload` 或显式类型转换：

```cpp
// 方法1：使用 QOverload
connect(sender, QOverload<int>::of(&Class::signal), receiver, &Receiver::slot);

// 方法2：显式类型转换
connect(sender, static_cast<void(Class::*)(int)>(&Class::signal), receiver, &Receiver::slot);
```

### Q3: Lambda 表达式中如何访问类成员？

**解决**：通过捕获列表捕获 `this` 指针：

```cpp
connect(ui->btn, &QPushButton::clicked, this,
        [this]() { this->ui->label->setText("clicked"); });
```

---

## 版本历史

| 版本 | 日期 | 说明 |
|------|------|------|
| 1.0 | 2026-03-17 | 初始版本，包含五种信号槽连接方式演示 |

---

## 许可证

本项目采用 MIT 许可证，可自由使用和修改。