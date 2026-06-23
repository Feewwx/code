######## https://b23.tv/8bvljo0

# [[初识C语言]]

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

# [[C语言初阶]]

## 1. 语句

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

### 6.1. 算数操作符 

` +  -  *  /  % `

`/` 取整除法 - `只有一边是小数时结果才能是小数`

`%` 取余数 - `两边必须是整数`

### 6.2. 移位操作符

` <<  >> `

`<<` 左移操作符

`>>` 右移操作符

> 移的是二进制位

整数的二进制表示有三种:
- 原码
- 反码
- 补码

```
正的整数的原码,反码,补码相同 [ 7 ]
00000000000000000000000000000111 - 原码
00000000000000000000000000000111 - 反码
00000000000000000000000000000111 - 补码
```

```
负的整数的原码,反码,补码是要计算的 [ -7 ]
10000000000000000000000000000111 - 原码
11111111111111111111111111111000 - 反码 (原码的符号位不变,其他位取反)
11111111111111111111111111111001 - 补码 (反码+1就是补码)
```

> 整数在内存中存储的是补码

**左移操作符:** 左边丢弃,右边补0

`00000000000000000000000000000111 => 00000000000000000000000000001110`
`7 => 14`

`11111111111111111111111111111001 => 11111111111111111111111111110010`
|-> 反推反码: 11111111111111111111111111110001
|-> 反推原码: 10000000000000000000000000001110
`-7 => -14`

- 左移有*2的效果
- 仅用于整形

**右移操作符:** 
> 算数移位 - 右边丢弃,左边补原符号位(正数0,负数1) (大多数)
> 逻辑移位 - 右边丢弃,左边补0

- 移位操作符箭头所指必须为正数!

### 6.3. 位操作符

` &   |   ^ `

`&` - 按(二进制)位与

`|` - 按(二进制)位或

`^` - 按(二进制)位异或

**&按位与:**
```c
#include <stdio.h>
int main() {
    int a = 3;
    int b = -5;
    printf("%d\n", a & b);  // 3
    return 0;
}
```
`00000000000000000000000000000011 - 3的补码`
`11111111111111111111111111111011 - -5的补码`
只要有一方为0,就返回0,两个同时为1,就返回1
00000000000000000000000000000011
|-> 反推反码: 00000000000000000000000000000011
|-> 反推原码: 00000000000000000000000000000011 - `结果(3)的原码`

**|按位或:**
```c
#include <stdio.h>
int main() {
    int a = 3;
    int b = -5;
    printf("%d\n", a | b);  // -5
    return 0;
}
```
`00000000000000000000000000000011 - 3的补码`
`11111111111111111111111111111011 - -5的补码`
只要有一方为1,就返回1,两个同时为0,就返回0
11111111111111111111111111111011
|-> 反推反码: 11111111111111111111111111111010
|-> 反推原码: 10000000000000000000000000000101 - `结果(-5)的原码`

**^按位异或:**
```c
#include <stdio.h>
int main() {
    int a = 3;
    int b = -5;
    printf("%d\n", a ^ b);  // -8
    return 0;
}
```
`00000000000000000000000000000011 - 3的补码`
`11111111111111111111111111111011 - -5的补码`
相异为1,相同为0
11111111111111111111111111111000
|-> 反推反码: 11111111111111111111111111110111
|-> 反推原码: 10000000000000000000000000001000 - `结果(-8)的原码`

### 6.4. 赋值操作符

` = `

**连续赋值:**

```c
    int a = 30;
    int b = 10;
    int c = 20;
    a = b = c+10;  // 从后向前赋值
```

**复合赋值符:**

` += -= *= /= %= >>= <<= &= |= ^=`

```c
a = a + 5 == a += 5;  // 同上
```

### 6.5. 单目操作符 

` !  -  +  &  sizeof  ~  --  ++  *  (类型) `

`!` - 逻辑反操作

`-` - 负值

`+` - 正值

`&` - 取地址

`sizeof` - 操作数的类型长度(以字节为单位)

`~` - 对一个数的二进制按位取反

`--` - 前置,后置--

`++` - 前置,后置++

`*` - 间接访问操作符(解引用操作符)

`(类型)` - 强制类型转换

**逻辑反操作(!):**

```c
if (flag) {
    // flag为真,进入if
}
if (!flag) {
    // flag为假,进入if
}
```

**对一个数的二进制位按位取反(~):**

```c
#include <stdio.h>

int main() {
    int a = 0;
    printf("%d\n", ~a);  // -1
    return 0;
}
```
`00000000000000000000000000000000 - 0的补码`
0=>1,1=>0
`11111111111111111111111111111111 - ~0的补码`
|-> 反推反码: 11111111111111111111111111111110
|-> 反推原码: 10000000000000000000000000000001 - `结果(-1)的原码`

**强制类型转换(类型):**

```c
int a = 3.14;  // warning
int a = (int)3.14;  // ok
```

### 6.6. 关系操作符

` >  >=  <  <=  !=  == `

### 6.7. 逻辑操作符

` && 逻辑与  || 逻辑或 `

**逻辑与(&&):**

```c
#include <stdio.h>

int main() {
    int t1 = 1;
    int t2 = 1;
    printf("%d\n", t1 && t2);  // 1
    int f1 = 0;
    printf("%d\n", t1 && f1);  // 0
    int f2 = 0;
    printf("%d\n", f1 && f2);  // 0
    return 0;
}  // 只要有一个为"假",就返回"假"
```

```c
#include <stdio.h>

int main() {
    int i = 0, a = 0, b = 2, c = 3, d = 4;
    i = a++ && ++b && d++;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    return 0;
}  // &&左边为假,右边就不计算了
```

**逻辑或(||):**

```c
#include <stdio.h>

int main() {
    int t1 = 1;
    int t2 = 1;
    printf("%d\n", t1 || t2);  // 1
    int f1 = 0;
    printf("%d\n", t1 || f1);  // 1
    int f2 = 0;
    printf("%d\n", f1 || f2);  // 0
    return 0;
}  // 只要有一个为"真",就返回"真"
```

```c
#include <stdio.h>

int main() {
    int i = 0, a = 0, b = 2, c = 3, d = 4;
    i = a++ || ++b || d++;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    return 0;
}  // ||左边为真,右边就不计算了
```

### 6.8. 条件操作符(三目操作符) 

`exp1(真/假) ? exp2(运行/不运行) : exp3(不运行/运行)`

### 6.9. 逗号表达式

` exp1, exp2, exp3, ...expN `

### 6.10. 下标引用操作符

` [] `

` arr[7] => *(arr + 7) => *(7 + arr) => 7[arr] `

### 6.11. 函数调用操作符

` () `

```c
#include <stdio.h>

int Add(int x, int y) {
    return x + y;
}

int main() {
    int a = 10;
    int b = 20;
    int c = Add(a, b);  // ()就是函数调用操作符
    return 0;
}
```

### 6.12. 结构体成员操作符

` .  -> `

`结构体.成员名`

`结构体指针->成员名`

```c
#include <stdio.h>
#include <string.h>

struct Stu {
    char name[20];
    int age;
    double score;
};

void set_stu(struct Stu *s) {
    // strcpy((*s).name, "zhangsan");
    // (*s).age = 20;
    // (*s).score = 100.0;
    strcpy(s->name, "zhangsan");
    s->age = 20;
    s->score = 100.0;
}

void print_stu(struct Stu s) {
    printf("%s %d %.1f\n", s.name, s.age, s.score);
}

int main() {
    struct Stu s = {0};
    set_stu(&s);
    print_stu(s);
    return 0;
}
```

### 6.13. 表达式求值

#### 6.13.1. 隐式类型转换

```c
#include <stdio.h>

int main() {
    char c = 1;
    printf("%u\n",sizeof(c));  // 1
    printf("%u\n",sizeof(+c));  // 4
    printf("%u\n",sizeof(-c));  // 4
    return 0;
}
```

> char参与运算时自动提升为int(历史遗留问题)

```c
#include <stdio.h>

int main() {
    char a = 5;
    char b = 126;
    printf("%d\n", a + b);  // -125
    return 0;
}
```

5的补码
00000000000000000000000000000101
`000000000000000000000000`00000101 (前面的截断)
|-> 00000101

126的补码
00000000000000000000000001111110
`000000000000000000000000`01111110 (前面的截断)
|-> 01111110

整形提升 

00000101 => 00000000000000000000000000000101
01111110 => 00000000000000000000000001111110

相加后的结果 => 00000000000000000000000010000011
`000000000000000000000000`10000011 (前面的截断)
|-> 10000011

整形提升(因为第一位是1,所以补1,反之补0)

10000011 => 11111111111111111111111110000011
|-> 反推反码: 11111111111111111111111110000010
|-> 反推原码: 10000000000000000000000001111101 - `结果(-125)的原码`

#### 6.13.2. 算数转换

long double            /|\
double                  | 向
float                   |
long long int           | 上
float                   |
unsigned long int       | 转
long int                |
unsigned int            | 换
int                     | (兼容)

> 写表达式时要确定好优先级,不要写"问题表达式"

如果写出的表达式不能通过操作符的属性确定唯一的计算路径,那这个表达式就是存在问题的

## 7. 指针

### 7.1. 指针是什么

指针就是内存单元的编号

平时口语中说的指针,通常指的是指针变量,是用来存放内存地址的变量

### 7.2. 指针和指针类型

```c
#include <stdio.h>

int main() {
    int a = 0x11223344;
    int *pa = &a;  // p是指针变量
    *pa = 0;       // 解引用操作符
    char *pc = (char *)pa;
    *pc = 0;       // 只改变了第一个地址
    printf("pa = %p\n", pa);          // 0x7fff71b91de4
    printf("pa + 1 = %p\n", pa + 1);  // 0x7fff71b91de8
    printf("pc = %p\n", pc);          // 0x7fff71b91de4
    printf("pc + 1 = %p\n", pc + 1);  // 0x7fff71b91de5
}
```

**结论1:**

指针类型决定了指针在被解引用时可以访问几个字节

- 如果是`int *`类型,解引用访问4个字节
- 如果是`char *`类型,解引用访问1个字节

**结论2:**

指针类型决定了指针+-1操作时,跳过几个字节

- 决定了指针的步长

### 7.3. 野指针

#### 7.3.1. 野指针成因

##### 7.3.1.1. 指针未初始化

```c
#include <stdio.h>

int main() {
    int *p;  // 指针未初始化,默认为初始值
    *p = 20;
    return 0;
}
```

##### 7.3.1.2. 指针越界访问

```c
#include <stdio.h>

int main() {
    int arr[10] = {0};
    int *p = arr;
    for(int i = 0; i <= 11; i++){
        // 当指针指向的范围超过数组arr的范围时,p就是野指针
        *(p++) = i;
    }
    return 0;
}
```

##### 7.3.1.3. 指针指向的空间释放

```c
#include <stdio.h>

int *test() {
    int a = 10;
    return &a;
}

int main() {
    int *p = test();
    // *p = NULL - *p是野狗(野指针)(NULL把野狗拴住了)
    printf("people1\n");
    printf("people2\n");  // 可能小狗跟着路人走了,路人越多,找回狗的概率就越小
    if (p != NULL) {
        printf("p = %d\n", *p);
    }  // 如果*p不是野狗,你可以回去找它
    return 0;
}
```

#### 7.3.2. 如何规避野指针

- 指针初始化
- 小心指针越界
- 指针指向空间释放及时放置NULL
- 避免返回局部变量地址
- 指针使用之前验证有效性

### 7.4. 指针运算

#### 7.4.1. 指针+-整数

```c
#include <stdio.h>

int main() {
    int arr[10] = {0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int *p = arr;
    for (int i = 0; i < sz; i++) {
        // *p = 1;
        // p++;
        *(p+i) = 1;
    }
    return 0;
}
```

```c
#include <stdio.h>
#include <string.h>

int my_strlen(char *str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int main() {
    int len = my_strlen("hello");
    printf("%d\n", len);
    return 0;
}
```

#### 7.4.2. 指针-指针

```c
#include <stdio.h>

int main() {
    int arr[10] = {0};
    printf("%d\n" &arr[9] - &arr[0]);   //  9
    printf("%d\n", &arr[0] - &arr[9]);  // -9
    return 0;
}
```

|指针-指针|得到的值是指针间元素的个数

```c
#include <stdio.h>
#include <string.h>

int my_strlen(char *str) {
    char *start = str;
    while (*str != '\0') {
        str++;
    }
    return (str - start);
}

int main() {
    int len = my_strlen("hello");
    printf("%d\n", len);
    return 0;
}
```

#### 7.4.3. 指针的关系运算

```c
#include <stdio.h>

#define N_VALUES 5

int main() {
    int values[N_VALUES] = {10, 20, 30, 40, 50};
    int *vp;

    for (vp = &values[N_VALUES]; vp > &values[0];) {
        *--vp = 0;
    }

    return 0;
}
```

```c
#include <stdio.h>

#define N_VALUES 5

int main() {
    int values[N_VALUES] = {11, 22, 33, 44, 55};
    int *vp;

    for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--) {
        *vp = 0;
    }

    return 0;
}
```

- 我们应该避免第二种实现方式,因为**标准**并不保证它可行

**标准规定:**
```
允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较
但是不允许与指向第一个元素之前的那个内存位置的指针进行比较
```

### 7.5. 指针和数组

```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("%p\n", arr);
    printf("%p\n", &arr[0]);
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int *p = arr;
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < sz; i++) {
        printf("&arr[%d] = %p ======= p + %d = %p\n", i, &arr[i], i, p + i);
    }
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int *p = arr;
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < sz; i++) {
        printf("%d", *(p + i));
    }
    return 0;
}
```

### 7.6. 二级指针

```c
#include <stdio.h>

int main() {
    int a = 0;
    int *pa = &a;     // 一级指针
    int **ppa = &pa;  // 二级指针
    return 0;
}
```
- *ppa => pa
- **ppa => a

指针理论上可以有∞级,但现实中没人会用二级以上的指针

### 7.7. 指针数组

- 存放指针的数组就是指针数组

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int c = 30;
    // int *pa = &a;
    // int *pb = &b;
    // int *pc = &c;
    // 太慢了
    int *parr[] = {&a, &b, &c};  // 存放指针的数组--指针数组
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    int arr1[4] = {1, 2, 3, 4};
    int arr2[4] = {2, 3, 4, 5};
    int arr3[4] = {3, 4, 5, 6};

    int *parr[3] = {arr1, arr2, arr3};  // 我愿称之为数组指针数组

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", parr[i][j]);  // parr[i][j] = *(*(parr + i) + j)
        }  // * 和 [] 都是解引用
        printf("\n");
    }
    return 0;
}
```

## 8. 结构体

### 8.1. 结构体的声明

#### 8.1.1. 结构的基础知识

- 结构是一些值的集合,这些值称为成员变量,结构的每个成员可以是不同类型的变量

#### 8.1.2. 结构的声明

```c
struct Peo {
    char name[10];
    char tele[12];
    char sex[5];
    int age;
};
```

#### 8.1.3. 结构成员的类型

- 结构的成员可以是标量,数组,指针,甚至是其他结构体

#### 8.1.4. 结构体变量的定义和初始化

```c
#include <stdio.h>

struct Peo {
    char name[10];
    char tele[12];
    char sex[5];
    int age;
} p1, p2;

struct Peo p3, p4;

struct St {
    struct Peo p;
    int num;
    float f;
};  // 结构体的嵌套

int main() {
    struct Peo p5, p6;  // 更推荐这种方式
    struct Peo p7 = {"zhangsan", "13800138000", "男", 20};
    struct St s1 = {{"lisi", "13800138000", "男", 20}, 100, 3.14};
    printf("%s %s %s %d\n", p7.name, p7.tele, p7.sex, p7.age);
    printf("%s %s %s %d %d %f\n", s1.p.name, s1.p.tele, s1.p.sex, s1.p.age, s1.num, s1.f);
    return 0;
}
```

### 8.2. 结构体成员的访问

```c
void print_peo(struct Peo p) {
    printf("%s %s %s %d\n", p7.name, p7.tele, p7.sex, p7.age);
    printf("%s %s %s %d\n", (*p7).name, (*p7).tele, (*p7).sex, (*p7).age);
}

void print_st(struct St s) {
    printf("%s %s %s %d %d %f\n", s1.p.name, s1.p.tele, s1.p.sex, s1.p.age, s1.num, s1.f);
    printf("%s %s %s %d %d %f\n", (*s1).p.name, (*s1).p.tele, (*s1).p.sex, (*s1).p.age, (*s1).num, (*s1).f);
}
```

### 8.3. 结构体传参

```c
#include <stdio.h>
struct Peo {
    char name[10];
    char tele[12];  
    char sex[5];
    int age;
};

struct St {
    char name[10];
    char tele[12];
    char sex[5];
    int age;
};

void print1(struct Peo p) {
    printf("%s %s %s %d\n", p.name, p.tele, p.sex, p.age);
}

void print2(struct St *s) {
    printf("%s %s %s %d\n", s->name, s->tele, s->sex, s->age);
}

int main() {
    struct Peo p = {"zhangsan", "13800138000", "男", 20};
    struct St s = {"lisi", "13800138000", "男", 20};

    print1(p);  // 传结构体
    print2(&s);  // 传地址

    return 0;
}
```

# [[C语言进阶]]

## 1. 数据的存储

### 1.1. 数据类型的介绍

#### 1.1.1. 整形家族:

- **char:** - 字符数据类型    
    - **signed char:** - 有符号字符数据类型
    - **unsigned char:** - 无符号字符数据类型
    #####
    字符的本质是ASCII码值,所以一般会划分到整型
    #####
    char 到底是 signed char 还是 unsigned char,char 标准是未定义的,取决与编译器
#####
- **short:** - 短整形
    - **signed short:** - 有符号短整形
    - **unsigned short:** - 无符号短整形
#####
- **int:** - 整形
    - **signed int:** - 有符号整形
    - **unsigned int:** - 无符号整形
    #####
    int => **signed int** 所有整形都一样 -- 除了char
#####
- **long:** - 长整形 
    - **signed long:** - 有符号长整形
    - **unsigned long:** - 无符号长整形
#####
- **long long:** - 更长的整形
    - **signed long long:** - 有符号更长的整形
    - **unsigned long long:** - 无符号更长的整形
#####

#### 1.1.2. 浮点家族:

- **float:** - 单精度浮点数
#####
- **double:** - 双精度浮点数
#####

#### 1.1.3. 构造类型:(自定义类型)

- **数组类型:**
    - **例如:** int arr[10] -- 类型为int [10]
#####
- **结构体类型:**
    - **struct**
#####
- **枚举类型:**
    - **enum**
#####
- **联合类型:**
    - **union**
#####

#### 1.1.4. 指针类型:

- **int \*p**i
- **char \*p**c
- **float \*p**f
- **void \*p**v
#####

#### 1.1.5. 空类型:

- **void**表示空类型(无类型)
- 通常用于函数的返回类型,函数的参数,指针类型
#####

```c
void test(void)
// 第一个void表示函数不会有返回值
// 第二个void表示函数不需要传任何参数
```

### 1.2. 整形在内存中的存储

#### 1.2.1. 原码,反码,补码

整数的二进制表示有三种:
- 原码
- 反码
- 补码

```
正的整数的原码,反码,补码相同 [ 7 ]
00000000000000000000000000000111 - 原码
00000000000000000000000000000111 - 反码
00000000000000000000000000000111 - 补码
```

```
负的整数的原码,反码,补码是要计算的 [ -7 ]
10000000000000000000000000000111 - 原码
11111111111111111111111111111000 - 反码 (原码的符号位不变,其他位取反)
11111111111111111111111111111001 - 补码 (反码+1就是补码)
```

> 整数在内存中存储的是补码

**为什么要这么做?**

- 1. 控制成本(原本cpu里有加法器和减法器,把减法变成加法就不需要减法器了,直接省一半的成本)

- 2. 如果使用原码,就会出现+0和-0的情况,与其每次x==0时判断,还不如直接杜绝

**为什么负数里反码变补码要加1?**

1 - 1 = 1 + (-1) -- 控制成本

> 如果要把钟表指针由6指向3,有两种方法

- 1. 往回拨三格 
- 2. 往后拨九格

- 9如何得到? ==> 补数=模−∣负数∣,也就是12−3=9

计算机的位数是有限的(比如8位,32位)
一个8位的标准加法器,就像一个只能显示0到255的计数器,到了256就会溢出归零
所以--8位计算机的"模"就是256

**256−Y=(255−Y)+1**

为什么要把256−Y写成255−Y+1?
 |
 |-因为255的二进制是全1(所有电脑的模-1的二进制都是全1)

所以1 - 1 = 1 + (-1) = 1的原码 + 1的反码 + 1 = 1的补码 + -1的补码
- -1 = {(255-1)+1} 在计算机的视角下,-1=255,到底是什么,取决于你给他带了什么颜色的眼镜

`例: 6−4=6+(256−4)=6+(255−4)+1=258(溢出)=2`

#### 1.2.2. 大小端介绍

```c
int a = 1;
```

```
00000000 00000000 00000000 00000001
0x    00       00       00       01
存放:
小端: 01       00       00       00

大端: 00       00       00       01
-----------------------------------
低地址          ==>            高地址
```

**个人电脑与手机(小端天下)**

**网络传输(大端天下)**

### 1.3. 浮点型在内存中的存储

```c
#include <stdio.h>

int main() {
    int n = 9;
    float *pFloat = (float*)&n;
    printf("n的值为:%d\n", n);             // n的值为:9
    printf("pFloat的值为:%f\n", *pFloat);  // pFloat的值为:0.000000
    *pFloat = 9.0;
    printf("n的值为:%d\n", n);             // n的值为:1091567616
    printf("*pFloat的值为:%f\n", *pFloat); // n的值为:1091567616
    return 0;
}
```
