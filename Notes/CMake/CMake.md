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
cmake_minimum_required(VERSION 3.16)
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

- `add_executable` 定义工程会生成一个可执行程序

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

# 当执行cmake命令之后,CMakeLists.txt 中的命令就会被执行,所以一定要注意给 cmake 命令指定路径的时候一定不能出错

# 执行命令之后,看一下源文件所在目录中是否多了一些文件:

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

# 我们可以看到在对应的目录下生成了一个makefile文件,此时再执行make命令,就可以对项目进行构建得到所需的可执行程序了

make
[ 16%] Building C object CMakeFiles/app.dir/main.c.o
[ 33%] Building C object CMakeFiles/app.dir/add.c.o
[ 50%] Building C object CMakeFiles/app.dir/sub.c.o
[ 66%] Building C object CMakeFiles/app.dir/mult.c.o
[ 83%] Building C object CMakeFiles/app.dir/div.c.o
[100%] Linking C executable app
[100%] Built target app

ls
 add.c   cmake_install.cmake   CMakeFiles       div.c    main.c     mult.c
󰡯 app     CMakeCache.txt        CMakeLists.txt   head.h   Makefile   sub.c
```

最终可执行程序app就被编译出来了(这个名字是在CMakeLists.txt中指定的)

### 2.2.2. VIP包间

通过上面的例子可以看出,如果在CMakeLists.txt文件所在目录执行了cmake命令之后就会生成一些目录和文件(包括 makefile 文件)
如果再基于makefile文件执行make命令,程序在编译过程中还会生成一些中间文件和一个可执行文件,这样会导致整个项目目录看起来很混乱
不太容易管理和维护,此时我们就可以把生成的这些与项目源码无关的文件统一放到一个对应的目录里边,比如将这个目录命名为build:

> 为了防止文件太乱,其实可以这样做

```bash
mkdir build
cd build
```

现在cmake命令是在build目录中执行的,但是CMakeLists.txt文件是build目录的上一级目录中
所以cmake 命令后指定的路径为..,即当前目录的上一级目录

```bash
cmake ..
```

当命令执行完毕之后,在build目录中会生成一个makefile文件

```bash
cd build
eza --tree
.
├── app
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
│   │   ├── add.c.o
│   │   ├── add.c.o.d
│   │   ├── build.make
│   │   ├── cmake_clean.cmake
│   │   ├── compiler_depend.make
│   │   ├── compiler_depend.ts
│   │   ├── depend.make
│   │   ├── DependInfo.cmake
│   │   ├── div.c.o
│   │   ├── div.c.o.d
│   │   ├── flags.make
│   │   ├── link.d
│   │   ├── link.txt
│   │   ├── main.c.o
│   │   ├── main.c.o.d
│   │   ├── mult.c.o
│   │   ├── mult.c.o.d
│   │   ├── progress.make
│   │   ├── sub.c.o
│   │   └── sub.c.o.d
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
└── Makefile
```

这样就可以在build目录中执行make命令编译项目,生成的相关文件自然也就被存储到build目录中了
这样通过cmake和make生成的所有文件就全部和项目源文件隔离开了

```bash
make
```

## 2.3. 私人定制

### 2.3.1. 定义变量

在上面的例子中一共提供了5个源文件,假设这5个源文件需要反复被使用
每次都直接将它们的名字写出来很麻烦且容易出错,此时我们就需要定义一个变量,将文件名对应的字符串存储起来
在cmake里定义变量需要使用set

```cmake
# set 指令的语法是:
# [] 中的参数为可选项,如果不需要可以不写
set(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])
```

- `VAR` 变量名

- `VALUE` 变量值

```cmake
# 方式1: 各个源文件之间使用空格间隔
set(SRC_LIST add.c  div.c   main.c  mult.c  sub.c)

# 方式2: 各个源文件之间使用分号 ; 间隔
set(SRC_LIST add.c;div.c;main.c;mult.c;sub.c)

add_executable(app  ${SRC_LIST})
```

### 2.3.2. 指定使用的C++标准

在编写C++程序的时候,可能会用到C++11,C++14,C++17,C++20等新特性
那么就要在编译的时候在编译命令中指定出要使用哪个标准:

```bash
# 指定出要使用C++11标准编译程序
gcc *.cpp -std=c++11 -o app
```

C++标准对应有一个宏叫作 `CMAKE_CXX_STANDARD`

在CMake中想要指定C++标准有两种方式:

#### 2.3.2.1. 在CMakeLists.txt中通过set命令指定

```cmake
#增加-std=c++11
set(CMAKE_CXX_STANDARD 11)
#增加-std=c++14
set(CMAKE_CXX_STANDARD 14)
#增加-std=c++17
set(CMAKE_CXX_STANDARD 17)
```

#### 2.3.2.2. 在执行cmake命令的时候指定出这个宏的值

```bash
#增加-std=c++11
cmake CMakeLists.txt文件路径 -DCMAKE_CXX_STANDARD=11
#增加-std=c++14
cmake CMakeLists.txt文件路径 -DCMAKE_CXX_STANDARD=14
#增加-std=c++17
cmake CMakeLists.txt文件路径 -DCMAKE_CXX_STANDARD=17
```

### 2.3.3. 指定输出的路径

在CMake中指定可执行程序的输出路径,也对应一个宏
叫作 `EXECUTABLE_OUTPUT_PATH`,它的值还是通过`set`命令进行设置:

```cmake
# 创建字符变量
set(PROJ /home/robin/Linux/Sort)
# 指定输出的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJ}/bin)
```

- 如果最后的子目录不存在,cmake会在配置阶段自动创建

- 由于可执行程序是基于cmake命令生成的makefile文件然后再执行make命令得到的,所以如果指定的是相对路径,那其中的.其实是makefile文件所在的目录

## 2.4. 搜索文件

如果一个项目里面源文件很多,不方便一一罗列,我们可以使用`aux_source_directory`或者`file`命令来搜索文件

### 2.4.1. aux_source_directory

在CMake中使用`aux_source_directory`命令可以查找某个路径下的所有源文件,命令格式为:

```cmake
aux_source_directory(<dir> <variable>)
```

- `dir` 要搜索的目录

- `variable` 将从dir目录下搜索到的源文件列表存储到该变量中

```cmake
cmake_minimum_required(VERSION 3.16)
project(CALC)
include_directories(${PROJECT_SOURCE_DIR}/include)
# 搜索 src 目录下的源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
add_executable(app  ${SRC_LIST})
```

### 2.4.2. file

在CMake中使用`file`命令可以搜索文件(file的用法不止于此),命令格式为:

```cmake
file(GLOB/GLOB_RECURSE 变量名 要搜索的文件路径和文件类型)
```

- `GLOB` 将指定目录下搜索到的满足条件的所有文件名生成一个列表,并将其存储到变量中

- `GLOB_RECURSE` 递归搜索指定目录,将搜索到的满足条件的文件名生成一个列表,并将其存储到变量中

> 搜索当前目录的src目录下所有的源文件,并存储到变量中

```cmake
file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
```
