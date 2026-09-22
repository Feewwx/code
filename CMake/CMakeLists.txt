# --- CMakeLists.txt ---
# CMake 读这个文件来决定怎么编译你的项目。
# 它本身不是 C 代码,是 CMake 自己的脚本语言,一行一条命令。

# 1. 最低版本要求。低于这个版本的 cmake 会直接报错,不让你配置
cmake_minimum_required(VERSION 3.16)

# 2. 项目名。第二个参数 C 表示这是个纯 C 项目(不写也行,写了省一次探测)
project(demo C)

# 3. 指定可执行文件输出到哪。不写这行的话,app 会生成在 build/ 里
#    第一行:定义一个变量存项目根目录(PROJ 是我起的名字,叫啥都行)
#    第二行:让所有 add_executable 的产物都输出到 ${PROJ}/bin
#    目录不存在也没事,CMake 会自己建
set(PROJ /home/fewx/code/CMake)
set(EXECUTABLE_OUTPUT_PATH ${PROJ}/bin)

# ↑ 上面这种是教程里的写法,手写绝对路径。
#   更好的写法是用 CMake 自带的变量,换目录/换电脑都不用改:
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# 4. 生成可执行文件。第一个参数是产物的名字,后面列出所有要编译的 .c
#    头文件(head.h)不用写进来,它会被 #include 自动带进去
add_executable(app
    main.c
    add.c
    sub.c
    mult.c
    div.c
)
