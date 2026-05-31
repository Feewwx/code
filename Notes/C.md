https://b23.tv/8bvljo0

# 初识C语言

## 1. 认识C语言

C语言代码中一定要有 `main` 函数(主函数)

`printf` 是一个库函数,专门用来打印输出的

- **std** - 标准(standard)
- **i** - input(输入)
- **o** - output(输出)

## 2. 第一个C语言项目

C语言规定: `main` 函数是程序的入口; `main` 函数有且只有一个

`void main()` --古老的写法,标准写法为 `int main()`

```c
#include <stdio.h>

int main() {
    printf("Hello World!\n");
    return 0;
}  // 故事的开头总是极其温柔
```

## 3. 数据类型

| 类型        | 说明         | 大小    |
|-------------|--------------|---------|
| `char`      | 字符数据类型 | 1个字节 |
| `short`     | 短整型       | 2个字节 |
| `int`       | 整型         | 4个字节 |
| `long`      | 长整型       | 8个字节 |
| `long long` | 更长的整型   | 8个字节 |
| `float`     | 单精度浮点型 | 4个字节 |
| `double`    | 双精度浮点型 | 8个字节 |

> `sizeof(long) >= sizeof(int)`

**计算机中的单位**

| 单位     | 说明   | 换算       |
|----------|--------|------------|
| bit      | 位     |            |
| byte     | 字节   | 1B=8bit    |
| kilobyte | 千字节 | 1KB=1024B  |
| megabyte | 兆字节 | 1MB=1024KB |
| gigabyte | 吉字节 | 1GB=1024MB |
| terabyte | 太字节 | 1TB=1024GB |
| petabyte | 拍字节 | 1PB=1024TB |

**输出格式控制符**

| 控制符 | 说明                    |
|--------|-------------------------|
| %d     | 十进制整数              |
| %c     | 字符                    |
| %f     | 单精度浮点型            |
| %lf    | 双精度浮点型            |
| %.1f   | 表示小数点后保留1位     |
| %s     | 字符串                  |
| %zu    | size_t 类型的无符号整数 |

```c
#include <stdio.h>

int main() {
    int age = 20;
    double price = 66.6;
    printf("age = %d, price = %.1f\n", age, price);
    return 0;
}
```

## 4. 变量和常量

### 4.1. 变量

#### 4.1.1. 变量的分类

变量分为两种:
- **局部变量:** `{}` 内部定义的变量
- **全局变量:** `{}` 外部定义的变量

```c
#include <stdio.h>

short age = 20;       // 年龄
int height = 180;     // 身高
float weight = 88.5;  // 体重

int main() {
    int a = 10;
    {
        int a = 20;
        printf("a = %d\n", a);  // 当全局变量和局部变量重名时,优先使用局部变量
    }
    return 0;
}
// 但是建议不要将全局变量和局部变量的名字写成一样的,避免混淆
```

- **`scanf`**: 是一个输入函数
- **`printf`**: 是一个输出函数

>`写一个代码,计算两个整数的和:`
```c
#include <stdio.h>

int main() {
    int num1 = 0;
    int num2 = 0;                  // 初始化
    scanf("%d %d", &num1, &num2);  // 输入2个整数 // 取地址符&
    int sum = num1 + num2;         // 求和
    printf("sum = %d\n", sum);     // 输出
    return 0;
}
```

#### 4.1.2. 变量的作用域和生命周期

**作用域:**
- 局部变量的作用域是变量所在的局部范围
- 全局变量的作用域是整个源文件

**生命周期:**
- 局部变量: 进入作用域生命周期开始,出作用域生命周期结束
- 全局变量: 整个程序的生命周期

### 4.2. 常量

#### 4.2.1. 字面常量

- **整数常量:** `10` `20` `-30`
- **浮点数常量:** `3.14` `66.6` `-0.88`
- **字符常量:** `'a'` `'b'` `'1'` `'*'`
- **字符串常量:** `"hello"` `"world"` `"123"`

#### 4.2.2. const 修饰的常变量

```c
#include <stdio.h>

int main() {
    const int a = 10;
    a = 20;  // err,常量不可修改
             // 在C语言中,const修饰的a,本质上是变量,但是不能直接修改,有常量的属性
    return 0;
}
```

#### 4.2.3. define 定义的标识符常量

预处理指令 `#define`
格式: `#define <标识符> <常量>`

```c
#include <stdio.h>

#define MAX 100
#define STR "hello"

int main() {
    printf("MAX = %d\n", MAX);
    int a = MAX;
    printf("a = %d\n", a);
    printf("STR = %s\n", STR);
    MAX = 200;  // err,标识符常量不可修改
    return 0;
}
```

#### 4.2.4. 枚举常量

```c
#include <stdio.h>

int main() {
    enum Color { RED, GREEN, BLUE };
    int num = 10;
    enum Color c = RED;  // 定义枚举常量c,并初始化为RED
    printf("num = %d, c = %d\n", num, c);
                         // 枚举常量本质上是整型常量,RED的值为0,GREEN的值为1,BLUE的值为2
    RED = 100;           // err,枚举常量不可修改
    return 0;
}
```

## 5. 字符串

```c
#include <stdio.h>
#include <string.h>

int main() {
    char arr1[4] = "abc";                    // 字符串以`'\0'`结尾但默认隐藏所以需为 [n+1]
    char arr2[] = "abc";                     // 自动计算数组大小为4
    char arr3[3] = { 'a', 'b', 'c' };        // 没有'\0'结尾
    printf("arr1 = %s\n", arr1);
    printf("arr2 = %s\n", arr2);
    printf("arr3 = %s\n", arr3);             // 未以'\0'结尾,可能打印出乱码
    char arr4[4] = { 'a', 'b', 'c', '\0' };  // 有'\0'结尾
    printf("arr4 = %s\n", arr4);             // 正确打印abc
                                             // 字符串结束的标志是'\0'
    printf("%d\n",strlen(arr1));             // strlen 计算字符串长度,不包括'\0'
    return 0;
}
```

## 6. 转义字符

```c
#include <stdio.h>
int main() {
    printf("Hello World!\n");      // \n 换行
    printf("Hello World!\t\n");    // \t 水平制表符 (tab键)
    printf("Hello \"World\"!\n");  // \" 打印双引号
    printf("Hello \\World\\!\n");  // \\ 打印反斜杠
    printf("Hello\0 World!\n");    // \0 字符串结束标志,后面的内容不打印
    return 0;
}
```

所有转义字符: `\?` `\'` `\"` `\\` `\a` `\b` `\f` `\n` `\r` `\t` `\v` `\0` `\ddd` `\xdd`

## 7. 注释

```c
#include <stdio.h>

int main() {
    // 单行注释
    /* 
    多行注释 
    */
    return 0;
}
```

## 8. 选择语句和循环语句

### 8.1. 选择语句

**选择语句:** `if` 语句 `switch` 语句

```c
#include <stdio.h>

int main() {
    int input = 0;
    printf("进入大学\n");
    printf("要好好学习吗? (1-是 0-否): ");
    scanf("%d", &input);
    if (input == 1) {
        printf("好offer\n");
    } else {
        printf("卖红薯\n");
    }
    return 0;
}
```

### 8.2. 循环语句

**循环语句:** `while` 语句 `do-while` 语句 `for` 语句

```c
#include <stdio.h>

int main() {
    int line = 0;
    printf("进入大学\n");
    while (line < 20) {
        printf("写代码:%d\n", line);
        line++;
    }
    if (line >= 20) {
        printf("好offer\n");
    } else {
        printf("继续加油\n");
    }
    return 0;
}
```

## 9. 函数

>`求两个任意整数的和`
```c
#include <stdio.h>

// 完整写法
int Add(int x, int y) {
    int z = x + y;
    return z;
}

// 简化写法
int Add(int x, int y) {
    return x + y;
}

int main() {
    int n1 = 0;
    int n2 = 0;
    scanf("%d %d", &n1, &n2);  // 输入
    int sum = Add(n1, n2);     // 求和
    printf("%d\n", sum);
    return 0;
}
```

## 10. 数组

```c
#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    // 数组的下标:  0   1   2   3   4   5   6   7   8   9   (类比成房号)
    printf("%d\n", arr[8]); // 通过下标访问数组元素,打印第9个元素90
    // 打印整个数列:
    int i = 0;
    while (i < 10) {
        printf("%d", arr[i]);
        i++;
    }
    return 0;
}
```

## 11. 操作符

| 类型                               | 操作符                                                                                                                                                                       |
|------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 算数操作符                     <br>| +  -  *  /  %                                                                                                                                                                |
| 移位操作符                     <br>| <<  >>                                                                                                                                                                       |
| 位操作符                       <br>| &  ^  \|  ~                                                                                                                                                                  |
| 赋值操作符                     <br>| =  +=  -=  *=  /=  %=  &=  ^=  \|=  >>=  <<=                                                                                                                                 |
| 单目操作符                     <br>| !逻辑反操作 -负值 +正值 &取地址 sizeof操作数的类型长度(以字节为单位)~对一个数的二进制按位取反 --前置 后置-- ++前置 后置++ *间接访问操作符 (解引用操作符) (类型) 强制类型转换 |                
| 关系操作符                     <br>| >  >=  <  <=  !=  ==                                                                                                                                                         |
| 逻辑操作符                     <br>| && 逻辑与 \|\| 逻辑或                                                                                                                                                        |
| 条件操作符<br>(三目操作符)         | ? :                                                                                                                                                                          |
| 逗号操作符                     <br>| ,                                                                                                                                                                            |

**条件操作符:** `exp1(真/假) ? exp2(运行/不运行) : exp3(不运行/运行)`

```c
#include <stdio.h>

int main() {
    int a = 0;
    scanf("%d", &a);
    int b = 10;
    a > b ? printf("a > b\n") : printf("a <= b\n");
    return 0;
}
```

**逗号操作符:** 可以将多个表达式用逗号隔开,并将它们作为一个表达式来运算
> **特点:** ` 从左向右依次计算,整个表达式的结果是最后一个表达式的结果 `

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int c = 0;
    int d = (c = a - 2, a = b + c, c - 3);
    printf("d = %d\n", d);
    return 0;
}
```

## 12. 常见关键字

```
auto   break   case   char   const   continue   default   do   double   else   enum
extern   float   for   goto   if   int   long   register   return   short   signed
sizeof   static   struct   switch   typedef   union   unsigned   void   volatile   while
```

### 12.1. 关键字 typedef

`typedef` 用于为类型起别名

```c
#include <stdio.h>

typedef unsigned int uint;
typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    uint num = 1;  // 等价于 unsigned int
    Node n;        // 等价于 struct Node n
    return 0;
}
```

### 12.2. 关键字 static

**修饰局部变量:** 局部变量出了作用域后不销毁(局部变量=>全局变量)
> `本质上,static修饰局部变量的时候,改变了变量的存储位置`

```c
#include <stdio.h>

void test() {
    static int a = 1;
    a++;
    printf("a = %d\n", a);
}

int main() {
    int i = 0;
    while (i < 10) {
        test();
        i++;
    }
    return 0;
}
```

**修饰全局变量:** 全局变量出了作用域后销毁(全局变量=>局部变量)
> `外部链接属性变为内部链接属性`

**修饰函数:** 一个函数本来是具有外部链接属性的,但是被static修饰后,就变成了内部链接属性

## 13. define 定义常量和宏

### 13.1. define 定义标识符常量

```c
#include <stdio.h>

#define NUM 100
int main() {
    printf("NUM = %d\n", NUM);
    int n = NUM;
    printf("n = %d\n", n);
    int arr[NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("arr[0] = %d\n", arr[0]);
    return 0;
}
```

### 13.2. define 定义宏

```c
#include <stdio.h>

#define ADD(x, y)                     ((x) + (y))  // 宏定义
//      宏名(宏的参数,参数是无类型)   宏体
int Add(int x, int y) { return x + y; }            // 函数定义

int main() {
    int a = 10;
    int b = 20;
    int c = ADD(a, b);
    printf("c = %d\n", c);
    c = Add(a, b);
    printf("c = %d\n", c);
    return 0;
}
```

## 14. 指针

### 14.1. 内存地址

```c
#include <stdio.h>

int main() {
    int a = 10;          // 向内存申请4个字节,储存10  
    &a;                  // 取地址操作符
    printf("%p\n", &a);  // 0x7fff7ee5a304,地址为第一个字节的地址
    int *p = &a;         // p就是指针变量
    // int 说明指针指向的是一个int类型的变量(a是int类型) *p 说明p是指针变量
    *p;                  // 解引用操作符,意思就是通过p中存放的地址,找到p所指向的对象,*p就是p指向的对象
    *p = 20;
    printf("%d\n", a);
    printf("%p\n", p);
    char ch = 'a';
    char *p1 = &ch;
    printf("%p\n", p1);
    return 0;
}
```

### 14.2. 指针变量的大小

```c
#include <stdio.h>

int main() {
    printf("%zu\n", sizeof(int *));     // 8
    printf("%zu\n", sizeof(char *));    // 8
    printf("%zu\n", sizeof(double *));  // 8
    printf("%zu\n", sizeof(float *));   // 8
    printf("%zu\n", sizeof(long *));    // 8
    printf("%zu\n", sizeof(short *));   // 8
    // 32位系统下,指针变量的大小为4字节;64位系统下,指针变量的大小为8字节
    return 0;
}
```

指针变量是用来存放地址的,不管是什么类型的指针,都是在创建指针变量

指针变量的大小取决于一个地址存放的时候需要多大的内存空间:
- **32位机器下的地址:** 32bit位 - 4byte
- **64位机器下的地址:** 64bit位 - 8byte

## 15. 结构体

```c
#include <stdio.h>

struct Stu {
    char name[10];
    int age;
    char sex[10];
    char telephone[12];
};

void print(struct Stu *ps) {
    printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).telephone);
    // -> 操作符:结构体指针变量->成员名
    printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->telephone);
}

int main() {
    struct Stu s = {"zhangsan", 20, "男", "13800138000"};
    // . 操作符:结构体变量.成员名
    printf("%s %d %s %s\n", s.name, s.age, s.sex, s.telephone);
    print(&s);
    return 0;
}
```

---

# C语言初阶 

## 1. 语句

### 1.1. 什么是语句

**语句可以分为以下几类:**

` 表达式语句  函数调用语句  控制语句  复合语句  空语句 `

控制语句可以分为以下三类:

- **条件/分支语句:** `if`语句 `switch`语句 
- **循环语句:** `do-while`语句 `while`语句 `for`语句
- **转向语句:** `break` `goto` `continue` `return`

## 2. 分支语句

### 2.1. if 语句

```c
#include <stdio.h>

int main() {
    int a = 10;
    if (a == 3) {
        printf("hehe\n");
    }
    int age = 20;
    if (age > 18) {
        printf("成年\n");
    }
    int age1 = 10;
    if (age1 < 18) {
        printf("未成年\n");
        printf("不能饮酒\n");
    } else
        printf("成年\n");
    int age2 = 10;
    scanf("%d", &age2);
    if (age2 < 18)
        printf("青少年\n");
    else if (age2 >= 18 && age2 < 28)
        printf("青年\n");
    else if (age2 >= 28 && age2 < 40)
        printf("中年\n");
    else if (age2 >= 40 && age2 < 60)
        printf("壮年\n");
    else if (age2 >= 60 && age2 < 100)
        printf("老年\n");
    else
        printf("不明\n");
    return 0;
}
```

```c
#include <stdio.h>

int test() {
    int a = 4;
    if (a == 4)
        return 1;
    return 0;
}
int main() {
    int r = test();
    printf("%d\n", r);
    return 0;
}
```

### 2.2. switch 语句

```c
#include <stdio.h>

int main() {
    int day = 0;  // 必须为整型
    scanf("%d", &day);
    switch (day) {
    case 1:  // 必须为字符或者整型
        printf("今天是周一\n");
        break;
    case 2:
        printf("今天是周二\n");
        break;
    case 3:
        printf("今天是周三\n");
        break;
    case 4:
        printf("今天是周四\n");
        break;
    case 5:
        printf("今天是周五\n");
        break;
    case 6:
        printf("今天是周六\n");
        break;
    case 7:
        printf("今天是周日\n");
        break;
    default:
        printf("今天是其他\n");
    }
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    int day = 0;
    scanf("%d", &day);
    switch (day) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("weekday\n");
            break;
        case 6:
        case 7:
            printf("weekend\n");
            break;
        default:
             printf("error\n");
             break;
    }
    return 0;
}
```

> `switch语句的嵌套:`

```c
#include <stdio.h>

int main() {
    int n = 0;
    int m = 0;
    switch (n) {
        case 1:
            m++;
        case 2:
            n++;
        case 3:
            switch (n) {
                case 1:
                    n++;
                case 2:
                    m++;
                    n++;
                    break;
            }
        case 4:
            m++;
            break;
        default:
            break;
    }
    printf("m = %d, n = %d\n", m, n);
    return 0;
}
```

## 3. 循环语句

### 3.1. while 语句

```c
#include <stdio.h>

int main() {
    if (1) {  // 不判断,直接执行
        printf("hehe\n");
    }
    while (1) {  // 死循环
        printf("hehe\n");
    }
}
```

> `打印1-10数字`

```c
#include <stdio.h>

int main() {
    int i = 1;
    while (i <= 10) {
        printf("%d\n", i);
        i++;
    }
    // 或者
    while (1) {
        if (i > 10) {
            break;  // 终止循环
        }
        continue;  // 跳过当前循环continue后面的代码,继续判断下一次循环
        printf("%d\n", i);
        i++;
    }
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    int ch = 0;
    while ((ch = getchar()) != EOF) {  // EOF:end of file
        putchar(ch);
    }
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    char password[20] = {0};
    printf("请输入密码:");
    scanf("%s", password);
    int ch = 0;
    while ((ch = getchar()) != EOF) {
    // 清除缓冲区
    }
    printf("请确认密码(Y/N):");
    int ret = getchar();
    if (ret == 'Y' || ret == 'y') {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    int i = 1;
    while (i <= 10) {
        if (i == 5)
            continue;
        printf("%d\n", i);
        i++;
    }  // 死循环
    return 0;
}
```

### 3.2. for 语句

```c
#include <stdio.h>

int main() {
    int i = 0;
    for (i = 1; i <= 10; i++) {
        if (i == 3) {
            continue;
        }
        if (i == 8) {
            break;
        }
        printf("%d ", i);
    }  // 1 2 4 5 6 7
    return 0;
}
```

> `for循环的判断部分省略意味着判断会恒成立`

```c
#include <stdio.h>

int main() {
    for (;;) {
        printf("hello");
    }  // 死循环
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("hehe\n");
        }
    }  // 循环10*10=100次
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    int x, y;
    for (x = 0, y = 0; x < 2 && y < 5; x++, y++) {
        printf("hehe\n");
    }  // 多个变量
    return 0;
}
```

### 3.3. do-while 语句

```c
#include <stdio.h>

int main() {
    int i = 1;
    do {
        printf("%d\n", i);
        i++;
    } while (i <= 10);
    return 0;
}
```

## 4. 函数

### 4.1. 函数的定义

在计算机科学中,子程序是一个大型程序中的部分代码,由一个或多个语句块组成

它负责完成某项特定任务,而且较于其他代码,具备相对的独立性

>`一般会有输入参数并有返回值,提供对过程的封装和细节的隐藏,这些代码通常被集成为软件库`

### 4.2. 函数的分类

#### 4.2.1. 库函数

>**库函数一般有:** `IO函数` `字符串操作函数` `字符操作函数` `内存操作函数` `时间/日期函数` `数学函数` `其他库函数`

https://cplusplus.com/reference/clibrary/
https://zh.cppreference.com/%E9%A6%96%E9%A1%B5

#### 4.2.2. 自定义函数

```c
#include <stdio.h>

int get_max(int x, int y) {
    return (x > y ? x : y);
}  // 返回什么前面数据类型就写什么,无返回值就写void

void test() { 
    printf("hello\n"); 
}    

int main() {
    test();
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int m = get_max(a, b);
    printf("%d\n", m);
    return 0;
}
```

>`交换两个整型变量`

```c
#include <stdio.h>

// 形式参数
void Swap(int x, int y) {
    int z = 0;
    z = x;
    x = y;
    y = z;
}  // 错误写法

// 当实参传递给形参的时候,形参是实参的一份临时拷贝
// 对形参的修改不会影响实参

void Swap(int *px, int *py) {
    int z = *px;
    *px = *py;
    *py = z;
}

int main() {
    int a = 0;
    int b = 0;
    // a和b为实参
    scanf("%d %d", &a, &b);
    // Swap(a, b);
    Swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}
```

### 4.3. 函数的参数

#### 4.3.1. 实际参数(实参)

真实传给函数的参数,叫**实参**

实参可以是:

- `常量`
- `变量`
- `表达式`
- `函数等`

无论实参是何种类型的量,在进行函数调用时,它们都必须有确定的值,以便把这些值传给形参

#### 4.3.2. 形式参数(形参)

形式参数是指函数名后括号中的变量,因为形式参数只有在函数被调用的过程中才能实例化(分配内存单元),所以叫形式参数

形式参数在函数调用完成之后就自动销毁了,因此形式参数只在函数中有效

### 4.4. 函数的调用

#### 4.4.1. 传值调用

函数的形参和实参分别占有不同的内存块,对形参的修改不会影响实参

#### 4.4.2. 传址调用

传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式

这种传参方式可以让函数和函数外边的变量建立起真正的联系,也就是函数内部可以直接操作函数外部的变量

```c
#include <stdio.h>

// 这是一个错误的示范,数组传参实际上传递的是数组首元素的地址,而不是整个数组
// 所以在函数内部计算一个函数参数部分的数组的元素个数是不靠谱的

int binary_search(int arr[], int k) {
    // 形参arr看上去是数组,本质是指针变量
    int sz = sizeof(arr) / sizeof(arr[0]);  // err
    int left = 0;
    int right = sz - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] < k) {
        left = mid + 1;
      } else if (arr[mid] > k) {
        right = mid - 1;
      } else {
        return mid;
      }
    }
  return -1;
}

int cmp(const void *a, const void *b) { 
    return *(int *)a - *(int *)b; 
}

int binary_search(int arr[], int k, int sz) {
    int left = 0;
    int right = sz - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] < k) {
        left = mid + 1;
      } else if (arr[mid] > k) {
        right = mid - 1;
      } else {
        return mid;  // 找到了返回下标
      }
    }
    return -1;  // 找不到
}

int main() {
    int arr[20] = {0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int k = 0;
    for (int i = 0; i < sz; i++) {
      scanf("%d", &arr[i]);
    }
    qsort(arr, sz, sizeof(int), cmp);
    printf("请输入数字:");
    scanf("%d", &k);
    int ret = binary_search(arr, k, sz);
    if (ret == -1) {
      printf("not found\n");
    } else {
      printf("found, index = %d\n", ret);
    }
    return 0;
}
```

>`形式参数和实际参数的名字可以相同,也可以不同`

```c
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n) {
    int j = 0;
    for (j = 2; j <= sqrt(n); j++) {
      if (n % j == 0) {
        return false;
      }
    }
    return true;
}
int main() {
    int i = 0;
    for (i = 100; i <= 200; i++) {
      if (isPrime(i)) {
        printf("%d\n", i);
      }
    }
    return 0;
}
```

```c
#include <stdio.h>

int Add(int n) { 
    return n + 1; 
}

int main() {
    int num = 0;
    int a = 0;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
      num = Add(num);
      printf("%d\n", num);
    }
    return 0;
}
```

### 4.5. 函数的嵌套调用和链式访问

#### 4.5.1. 嵌套调用

```c
#include <stdio.h>

void new_line() { 
    printf("hehe\n"); 
}

void three_line() {
    int i = 0;
    for (i = 0; i < 3; i++) {
      new_line();
    }
}

int main() {
    three_line();
    return 0;
}
```

```c
#include <stdio.h>

int Add(int x, int y) {
    return x + y;
    int Sub(int x, int y) { return x - y; }
}  // 不是这样嵌套!

int main() {
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    printf("%d", Add(a, b));
    return 0;
}
```

>`函数可以嵌套调用,但是不能嵌套定义`

#### 4.5.2. 链式访问

```c
#include <stdio.h>
#include <string.h>

int main() {
    char arr[20] = "hello";
    int ret = strlen(strcat(arr, "bit"));
    printf("%d\n", ret);
    return 0;
}
```

```c
#include <stdio.h>

int main() {
// printf的返回值是打印字符的个数
//  打印1(2)     打印2(43)    打印43
    printf("%d", printf("%d", printf("%d", 43)));
    return 0;
}  // 结果:打印4321
```

```c
Add(int x, int y) { return x + y; }
// 函数不写返回类型的时候,默认返回int类型
```

```c
#include <stdio.h>
void test() { 
    printf("hello\n"); 
}
int main() {
    test(100);  // 传了参数,但人家函数没用
    test();
    return 0;
}
```

```c
int main(void) {}
// 明确说明这个main函数没有参数
```

```c
// main函数有三个参数
int main(int argc, char *argv[], char *envp[]) {}
```

### 4.6. 函数的声明和定义

#### 4.6.1. 函数声明

```c
int Add(int, int);
#include "Add.h"  // 自定义函数用双引号
// 如果是Add.lib,则需要手动导入静态库:
#pragma comment (lib, "Add.lib")
```

告诉编译器有一个函数叫什么,参数是什么,返回类型是什么

函数的声明一般要放在头文件中

#### 4.6.2. 函数定义

```c
int Add(int x, int y) {}
```

函数的定义是指函数的具体实现,交代函数的功能实现

>`本质 => 创建函数`

### 4.7. 函数的递归

#### 4.7.1. 什么是递归

程序(函数)调用自身的编程技巧称为递归(recursion)

>**`递归的主要思考方式在于:大事化小`**

>`分次输出输入的数字`

```c
#include <stdio.h>

void print(unsigned int n) {
  if (n > 9) {
    print(n / 10);
  }
  printf("%d", n % 10);
}

int main() {
  unsigned int num = 0;
  scanf("%d", &num);
  print(num);
  return 0;
}
```

#### 4.7.2. 递归的两个必要条件

- 存在限制条件,当满足这个限制条件的时候,递归便不再继续
- 每次递归调用之后越来越接近想要的值

>`计算字符串的长度`

```c
#include <stdio.h>

// int my_strlen(char str[])  // 函数部分写出数组的形式
int my_strlen(char *str) {    // 参数部分写出指针的形式
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

// 递归求解
int  my_strlen(char *str) {
    if (*str != '\0') 
        return 1 + my_strlen(str + 1);
    else
        return 0;
}

int main() {
    char arr[] = "abc";
    int len = my_strlen(arr);
    printf("%d\n", len);
    return 0;
}
```

#### 4.7.3. 递归与迭代

>`n的阶乘`

```c
#include <stdio.h>

int fac(int n) {
    if (n <= 1)
        return 1;
    else
        return n * fac(n - 1);
}

// 迭代的方式-非递归
int fac(int n) {
    int ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

int main(){
    int n = 0;
    scanf("%d", &n);
    int ret = fac(n);
    printf("%d\n", ret);
    return 0;
}
```

>`第n个斐波那契数`

**斐波那契数列:** 1 1 2 3 5 8 13 21 34 55 89 144 ...

```c
#include <stdio.h>

int feewwx(int n) {
    if (n <= 1)
        return n;
    return feewwx(n - 1) + feewwx(n - 2);
}

// 此情况下,递归运行太慢,可以用迭代
int feewwx(int n) {
    int a = 1;
    int b = 1;
    int c = 1;  // 用来防止输入为1和2的情况
    while (n >= 3) {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", feewwx(n));
    return 0;
}
```

## 5. 数组

### 5.1. 一维数组的创建和初始化

#### 5.1.1. 数组的创建

>`数组是一组相同类型元素的集合`

**数组的创建方式:**

`type_t arr_name [const_n]`

- `type_t` 是指数组的元素类型
- `arr_name` 是指数组的名字
- `const_n` 是一个常量表达式,用来指定数组的大小

```c
int arr[n];
// 在c99标准之前,数组的大小必须是常量或者常量表达式
// 在c99标准之后,数组的大小可以是变量,为了支持变长数组
```

#### 5.1.2. 数组的初始化

```c
// 不完全初始化,剩余的元素默认初始化为0
int arr[10] = {1, 2 ,3};
char arr[10] = {'a', 'b', 'c'};
char arr1[10] = "abc";
// 完全初始化
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < sz; i++) {
        printf("%d\n", arr[i]);
        printf("&arr[%d] = %p\n", i, &arr[i]);
    }
    return 0;
}
```

### 5.2. 二维数组的创建和初始化

#### 5.2.1. 二维数组的创建

```c
int arr[3][4];
char arr[3][5];
double arr[2][4];
```

#### 5.2.2. 二维数组的初始化

```c
int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
char arr[3][5] = {{'a', 'b', 'c', 'd', 'e'}, {'f', 'g', 'h', 'i', 'j'}, {'k', 'l', 'm', 'n', 'o'}};
double arr[2][4] = {{1.1, 2.2, 3.3, 4.4}, {5.5, 6.6, 7.7, 8.8}};
int arr1[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};  // 行可以省略,但是列不能省略
```

可以理解为:**一维数组的嵌套**

#### 5.2.3. 二维数组的使用

\[0\]\[0\] \[0\]\[1\] \[0\]\[2\] \[0\]\[3\]
\[1\]\[0\] \[1\]\[1\] \[1\]\[2\] \[1\]\[3\]
\[2\]\[0\] \[2\]\[1\] \[2\]\[2\] \[2\]\[3\]

```c
#include <stdio.h>

int main() {
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
            printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

>`二维数组在内存中也是连续存放的,一行存完存下一行`

### 5.3. 数组越界

```c
#include <stdio.h>

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
```

### 5.4. 数组作为函数参数

#### 5.4.1. 冒泡排序法

```c
#include <stdio.h>

// 形参是数组的形式
void bubble_sort(int arr[], int sz) {
    // int sz = sizeof(arr) / sizeof(arr[0]);
    // err,数组名本质上是数组首元素的地址,因此应该使用指针来接收
    // 这里的arr看似是数组,但是实际上是指针变量
    for (int i = 0; i < sz - 1; i++) {          // 趟数
        for (int j = 0; j < sz - 1 - i; j++) {  // 一趟冒泡排序
            if (arr[j] > arr[j + 1]) {          // 交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, sz);
    for (int i = 0; i < sz; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
```

#### 5.4.2. 数组名

##### 5.4.2.1. 一维数组的数组名的理解

数组名确实能表示数组首元素的地址,**但是有两个例外**:

- sizeof(数组名):这里的数组名表示整个数组,计算的是整个数组的大小
- &数组名:这里的数组名表示整个数组,取出的是整个数组的地址

```c
#include <stdio.h>

int main() {
    int arr[10] = {0};

    // 首元素地址
    printf("%p\n", arr);          // 0x7ffc02bce4f0
    printf("%p\n", arr + 1);      // 0x7ffc02bce4f4

    // 首元素地址
    printf("%p\n", &arr[0]);      // 0x7ffc02bce4f0
    printf("%p\n", &arr[0] + 1);  // 0x7ffc02bce4f4

    // 数组地址
    printf("%p\n", &arr);         // 0x7ffc02bce4f0
    printf("%p\n", &arr + 1);     // 0x7ffc02bce518

    int n = sizeof(arr);
    printf("%d\n", n);

    return 0;
}
```

##### 5.4.2.2. 二维数组的数组名的理解

二维数组的首元素地址是第一行的地址

```c
#include <stdio.h>

int main() {
    int arr[3][4] = {0};

    printf("%p\n", arr);      // 0x7ffe950eec50   
    printf("%p\n", arr + 1);  // 0x7ffe950eec60     
    
    printf("%d\n", sizeof(arr));                         // 48
    printf("%d\n", sizeof(arr[0]));                      // 16
    printf("%d\n", sizeof(arr[0][0]));                   // 4
    printf("%d\n", sizeof(arr) / sizeof(arr[0]));        // 3
    printf("%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));  // 4

    return 0;
}
```

### 5.5. 数据实例

#### 5.5.1. 三子棋

test.c 测试游戏的逻辑
```c
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void menu() {
    printf("**********************************\n");
    printf("********  1.play  0.exit  ********\n");
    printf("**********************************\n");
}

void game() {
    char ret = ' ';
    char board[ROW][COL] = {0};
    // 初始化棋盘的函数
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
    // 下棋
    while (1) {
        PlayerMove(board, ROW, COL);
        // 判断输赢
        ret = IsWin(board, ROW, COL);
        if (ret != 'C') {
            break;
        }
        DisplayBoard(board, ROW, COL);
        ComputerMove(board, ROW, COL);
        // 判断输赢
        ret = IsWin(board, ROW, COL);
        if (ret != 'C') {
            break;
        }
        DisplayBoard(board, ROW, COL);
    }
    if (ret == '*') {
        printf("玩家赢\n");
    } else if (ret == '#') {
        printf("电脑赢\n");
    } else {
        printf("平局\n");
    }
    DisplayBoard(board, ROW, COL);
}

int main() {
    srand((unsigned)time(NULL));
    int input = 0;
    do {
        menu();  // 打印菜单
        printf("请选择:>");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("bye\n");
                break;
            default:
                printf("error\n");
                break;
        }
    } while (input);
    return 0;
}
```

game.c 游戏代码的实现
```c
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {

        // 打印数据
        for (int j = 0; j < col; j++) {
            printf(" %c ", board[i][j]);
            if (j < col - 1) {
                printf("|");
            }
        }
        printf("\n");

        // 打印分割信息
        if (i < row - 1) {
            for (int j = 0; j < col; j++) {
                printf("---");
                if (j < col - 1) {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}

void PlayerMove(char board[ROW][COL], int row, int col) {
    int x = 0;
    int y = 0;
    printf("玩家下棋:>\n");
    while (1) {
        printf("请输入坐标:>");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col) {
            if (board[x - 1][y - 1] == ' ') {
                board[x - 1][y - 1] = '*';
                break;
            } else {
                printf("棋子已经存在,请重新输入:>");
            }
        } else {
            printf("输入错误,请重新输入:>");
        }
    }
}

void ComputerMove(char board[ROW][COL], int row, int col) {
    printf("电脑下棋:>\n");
    int x = 0;
    int y = 0;
    while (1) {
        x = rand() % row;  // 0~2
        y = rand() % col;  // 0~2
        if (board[x][y] == ' ') {
            board[x][y] = '#';
            break;
        }
    }
}

// 如果棋盘是全满的,则返回1
// 不是全满的,则返回0
int IsFull(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

char IsWin(char board[ROW][COL], int row, int col) {
    
    // 行
    for (int i = 0; i < row; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
            return board[i][1];
        } 
    }

    // 列
    for (int i = 0; i < col; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') {
            return board[1][i];
        } 
    }

    // 对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
        return board[1][1];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
        return board[1][1];
    }

    // 没人赢
    if (IsFull(board, row, col)) {
        return 'Q';
    }

    // 游戏继续
    return 'C';
}
```

game.h 游戏代码的头文件(函数声明,符号定义)
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3  // 棋盘的行数
#define COL 3  // 棋盘的列数

void menu();
void game();

// 初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

// 打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

// 计算机下棋
void ComputerMove(char board[ROW][COL], int row, int col);

// 玩家赢-* // 电脑赢-# // 平局-Q // 继续-C
char IsWin(char board[ROW][COL], int row, int col);
```

#### 5.5.2. 扫雷

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char out_arr[11][11];
    char in_arr[11][11];

    memset(in_arr, '0', sizeof(in_arr));
    memset(out_arr, '#', sizeof(out_arr));

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int x = rand() % 9 + 1;
        int y = rand() % 9 + 1;
        if (in_arr[x][y] == '0') {
            in_arr[x][y] = '1';
        } else {
            i--;
        }
    }

    printf("**********************************\n");
    printf("********  1.play  0.exit  ********\n");
    printf("**********************************\n");

    int a = 0;
    int win = 0;
    printf("请选择:>");
    scanf("%d", &a);
        if (a == 1) {

        for (int i = 0; i < 10; i++) {
            printf("%d  ", i);
        }
        printf("\n");

        for (int i = 1; i < 10; i++) {
            printf("%d  ", i);
            for (int j = 1; j < 10; j++) {
                printf("%c  ", in_arr[i][j]);
            }
            printf("\n");
        }

        printf("\n");
        printf("\n");

        for (int i = 0; i < 10; i++) {
            printf("%d  ", i);
        }
        printf("\n");

        for (int i = 1; i < 10; i++) {
            printf("%d  ", i);
            for (int j = 1; j < 10; j++) {
                printf("%c  ", out_arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        while (1) {

            printf("请输入坐标");
            int x = 0;
            int y = 0;
            scanf("%d%d", &y, &x);

            if (x > 10 || x < 1 || y > 10 || y < 1) {
                printf("请输入正确的坐标");
                return 0;
            } else if (in_arr[x][y] == '1') {
                printf("game over");
                return 0;
            } else {
                int a = in_arr[x + 1][y + 1] + in_arr[x][y + 1] + in_arr[x - 1][y + 1] +
                        in_arr[x + 1][y] + in_arr[x - 1][y] + in_arr[x + 1][y - 1] +
                        in_arr[x][y - 1] + in_arr[x - 1][y - 1];
                out_arr[x][y] = a - 8 * '0' + '0';
            }
            for (int i = 0; i < 10; i++) {
                printf("%d  ", i);
            }
            printf("\n");

            for (int i = 1; i < 10; i++) {
                printf("%d  ", i);
                for (int j = 1; j < 10; j++) {
                    printf("%c  ", out_arr[i][j]);
                }
                printf("\n");
            }
            printf("\n");

            win++;
            if (win == 71) {
                printf("you win");
                return 0;
            }
        }
    } else if (a == 0) {
        return 0;
    } else {
        printf("请输入正确的数字");
        return 0;
    }
    return 0;
}
```

## 6. 操作符
