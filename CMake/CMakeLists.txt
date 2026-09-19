# --- CMakeLists.txt ---
# CMake 读这个文件来决定怎么编译你的项目。
# 它本身不是 C 代码,是 CMake 自己的脚本语言,一行一条命令。

# 1. 最低版本要求。低于这个版本的 cmake 会直接报错,不让你配置
cmake_minimum_required(VERSION 3.16)

# 2. 项目名。第二个参数 C 表示这是个纯 C 项目(不写也行,写了省一次探测)
project(demo C)

# 3. 生成可执行文件。第一个参数是产物的名字,后面列出所有要编译的 .c
#    头文件(head.h)不用写进来,它会被 #include 自动带进去
add_executable(app
    main.c
    add.c
    sub.c
    mult.c
    div.c
)
