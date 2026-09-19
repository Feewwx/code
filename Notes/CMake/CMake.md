####### https://www.bilibili.com/video/BV14s4y1g7Zj
####### https://subingwen.cn/cmake/CMake-primer/
####### https://subingwen.cn/cmake/CMake-advanced/

# 1. CMake概述

我们在学习C语言的时候,我们知道源文件是如何变成可执行文件的

源文件(.C/.CPP)-预处理-编译-汇编->目标文件(.o/.obj)-链接->可执行文件

但是当源代码较多的时候,这些步骤会变得很繁琐,而且容易出错

这时候我们就需要一个项目构建工具来帮助我们完成这些步骤--make

首先我们要写一份脚本文件(makefile)

写好 Makefile 之后敲 make,它按里面的规则和依赖关系,只重新编译该重编的部分

大多数IDE软件都集成了make,比如:VS的nmake,linux下的GNU make,Qt的qmake等

但是,makefile通常依赖于当前的编译平台,且编写Makefile时依赖关系难处理,且编写Makefile的工作量较大



而CMake恰好能解决上述问题,其允许开发者指定整个工程的编译流程

再根据编译平台,自动生成本地化的Makefile和工程文件,最后用户只需make编译即可

```
CMakeLists.txt(编写文件)->cmake(执行命令)->Makefile(文件)->make(调用gcc)->可执行文件
```

可以看出来CMake的优点:

- 跨平台
- 能够管理大型项目
- 简化编译构建过程和编译过程
- 可扩展:可以为CMake编写特定功能的模块

> CMake 一个字节都不编译。它只是把编译命令写成脚本

CMake不仅可以生成可执行文件,还可以生成库文件(动态库/静态库)

# 2. CMake的使用

## 2.1. 注释

### 2.1.1. 注释行

`CMake`使用`#`进行**行注释**,可以放在任意位置

```cmake
# 这是一个行注释
```

### 2.1.2. 注释块

`CMake`使用`#[[]]`形式进行**块注释**

```cmake
#[[ 
这是
一个
块注释 
]]
```

## 2.2. 只有源文件

### 2.2.1. 共处一室

#### 2.2.1.1. 准备工作

为了方便讲解,我们先新建几个文件

> add.c
```c
#include <stdio.h>
#include "head.h"

int add(int a, int b) {
    return a + b;
}
```

> sub.c
```c
#include <stdio.h>
#include "head.h"

int subtract(int a, int b)
{
    return a-b;
}
```

> mult.c
```c
#include <stdio.h>
#include "head.h"

int multiply(int a, int b)
{
    return a*b;
}
```

> div.c
```c
#include <stdio.h>
#include "head.h"

double divide(int a, int b)
{
    return (double)a/b;
}
```

> head.h
```c
#ifndef _HEAD_H
#define _HEAD_H
// 加法
int add(int a, int b);
// 减法
int subtract(int a, int b);
// 乘法
int multiply(int a, int b);
// 除法
double divide(int a, int b);
#endif
```

> main.c
```c
#include <stdio.h>
#include "head.h"

int main()
{
    int a = 20;
    int b = 12;
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", subtract(a, b));
    printf("a * b = %d\n", multiply(a, b));
    printf("a / b = %f\n", divide(a, b));
    return 0;
}
```

#### 2.2.1.2. 目录结构

> 上述文件的目录结构如下：

```bash
eza --tree
.
├── add.c
├── div.c
├── head.h
├── main.c
├── mult.c
└── sub.c
```

#### 2.2.1.3. 添加CMakeLists.txt

在上述文件目录下新建一个文件`CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.10)
project(CALC)
add_executable(app add.c sub.c mult.c div.c main.c)
```

- `cmake_minimum_required` 指定CMake的最低版本
    - 可选,非必须,但如果不加可能会有警告

- `project` 定义工程名称,并可指定工程的版本,工程描述,web主页地址,支持的语言(默认情况支持所有语言)
如果不需要这些都是可以忽略的,只需要指定出工程名称即可

```cmake
# PROJECT 指令的语法是:
project(<PROJECT-NAME> [<language-name>...])
project(<PROJECT-NAME>
       [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
       [DESCRIPTION <project-description-string>]
       [HOMEPAGE_URL <url-string>]
       [LANGUAGES <language-name>...])
```

- `add_executable` 定义工程会胜场一个可执行程序

```cmake
add_executable(可执行程序名 源文件名称)
```

-
    - 这里的可执行程序名和project中的项目名没有任何关系
    - 源文件可以是一个也可以是多个,如有多个可用空格或`;`间隔

```cmake
# 样式1
add_executable(app add.c div.c main.c mult.c sub.c)
# 样式2
add_executable(app add.c;div.c;main.c;mult.c;sub.c)
```

#### 2.2.1.4. 执行CMake命令

将 CMakeLists.txt 文件编辑好之后,就可以执行 cmake命令 了

```bash
cmake CMakeLists.txt文件所在路径
```

> 例子

```bash
pwd
/home/fewx/code/CMake

cmake .
-- The C compiler identification is GNU 16.2.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /home/fewx/code/CMake

eza --tree
.
├── add.c
├── cmake_install.cmake
├── CMakeCache.txt
├── CMakeFiles
│   ├── 4.4.3
│   │   ├── CMakeCCompiler.cmake
│   │   ├── CMakeDetermineCompilerABI_C.bin
│   │   ├── CMakeSystem.cmake
│   │   └── CompilerIdC
│   │       ├── a.out
│   │       ├── CMakeCCompilerId.c
│   │       └── tmp
│   ├── app.dir
│   │   ├── build.make
│   │   ├── cmake_clean.cmake
│   │   ├── compiler_depend.make
│   │   ├── compiler_depend.ts
│   │   ├── depend.make
│   │   ├── DependInfo.cmake
│   │   ├── flags.make
│   │   ├── link.txt
│   │   └── progress.make
│   ├── cmake.check_cache
│   ├── CMakeConfigureLog.yaml
│   ├── CMakeDirectoryInformation.cmake
│   ├── CMakeScratch
│   ├── InstallScripts.json
│   ├── Makefile.cmake
│   ├── Makefile2
│   ├── pkgRedirects
│   ├── progress.marks
│   └── TargetDirectories.txt
├── CMakeLists.txt
├── div.c
├── head.h
├── main.c
├── Makefile
├── mult.c
└── sub.c

make
[ 16%] Building C object CMakeFiles/app.dir/main.c.o
[ 33%] Building C object CMakeFiles/app.dir/add.c.o
[ 50%] Building C object CMakeFiles/app.dir/sub.c.o
[ 66%] Building C object CMakeFiles/app.dir/mult.c.o
[ 83%] Building C object CMakeFiles/app.dir/div.c.o
[100%] Linking C executable app
[100%] Built target app

ls
 add.c   cmake_install.cmake   CMakeFiles       div.c    main.c     mult.c
󰡯 app     CMakeCache.txt        CMakeLists.txt   head.h   Makefile   sub.c
```
