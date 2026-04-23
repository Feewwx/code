// 初识C语言

// 1.认识C语言
// C语言代码中一定要有main函数
// 主函数

// printf是一个库函数
// 专门用来打印输出的

// std-标准
// i-input
// o-output

// 2.第一个C语言项目
#include <stdio.h>
#include <string.h> //包含字符串操作相关的函数的头文件

// 标准的主函数的写法
// void main()-古老的写法

// C语言规定
// main函数是程序的入口
// main函数有且只有一个

// int main() {
//   printf("Hello, World!\n");
//   return 0;
// }//故事的开头总是极其温柔

// 3.数据类型
// char-字符数据类型-1个字节               计算机中的单位：
// short-短整型-2个字节                    bit-比特位
// int-整形-4个字节                        byte-字节-8个比特位
// long-长整型-4个字节                     kb-千字节-1024字节
// long long-更长的整型-8个字节            mb-兆字节-1024千字节
// float-单精度浮点型-4个字节              gb-吉字节-1024兆字节
// double-双精度浮点型-8个字节             tb-太字节-1024吉字节
// 例如：66.6-小数-浮点型  666-整数-整型   pb-拍字节-1024太字节
// sizeof(long)>=sizeof(int)

// int main() {
//   int age = 20;
//   double price = 66.6;
//   printf("age = %d, price = %.1f\n", age, price);
//   return 0;
// }

// 输出格式控制符:
//%d-十进制整数
//%c-字符
//%f-浮点数-float
//%lf-双精度浮点数-double
//%s-字符串
//%.1f-表示小数点后保留1位
//%zu-size_t类型的无符号整数

// 4.变量和常量:局部变量和全局变量
// 变量分为两种：局部变量和全局变量
// 局部变量-{}内部定义的变量
// 全局变量-{}外部定义的变量

// /* short age = 20;//年龄
// int height = 180;//身高
// float weight = 88.5;//体重 */

// int main() {
//   int a = 10;
//   {
//     int a = 20;
//     printf("a = %d\n", a); // 当全局变量和局部变量重名时，优先使用局部变量
//   }
//   return 0;
// }
// 但是建议不要将全局变量和局部变量的名字写成一样的，避免混淆

// 写一个代码，计算两个整数的和
// scanf  是一个输入函数
// printf 是一个输出函数

// int main() {
//   int num1 = 0;
//   int num2 = 0;                 // 初始化
//   scanf("%d %d", &num1, &num2); // 输入2个整数//取地址符&
//   int sum = num1 + num2;        // 求和
//   printf("%d\n", sum);          // 输出
//   return 0;
// }

// 5.变量的作用域和生命周期
// 作用域：局部变量的作用域是变量所在的局部范围
// 全局变量的作用域是整个源文件
// 生命周期：局部变量：进入作用域生命周期开始，出作用域生命周期结束
// 全局变量：整个程序的生命周期

// 6.常量
// 6.1.字面常量
// 整数常量：10、20、-30
// 浮点数常量：3.14、66.6、-0.88
// 字符常量：'a'、'b'、'1'、'*'
// 字符串常量："hello"、"bit"

// 6.2.const修饰的常变量
// int main() {
//   const int a = 10;
//   a = 20; // 错误，常量不可修改
//   // 在C语言中，const修饰的a，本质上是变量，但是不能直接修改，有常量的属性
//   return 0;
// }

// 6.3.define定义的标识符常量
// 预处理指令#define
// 格式：#define 标识符 常量值
// int main() {
// #define MAX 100
// #define STR "hello"
//   printf("%d\n", MAX);
//   int a = MAX;
//   printf("%d\n", a);
//   printf("%s\n", STR);
//   MAX = 200; // 错误，标识符常量不可修改
//   return 0;
// }

// 6.4.枚举常量
// int main() {
//   enum Color { RED, GREEN, BLUE };
//   int num = 10;       // 定义整型变量num，并初始化为10
//   enum Color c = RED; // 定义枚举变量c，并初始化为RED
//   printf("num = %d, c = %d\n", num, c); //
//   枚举常量本质上是整型常量，RED的值为0，GREEN的值为1，BLUE的值为2 RED = 100;
//   // 错误，枚举常量不可修改 return 0;
// }

// 7.字符串
//'a'是字符
// char ch = 'a';
//"abc"是字符串

// int main() {
//   char arr1[4] = "abc"; // 字符串以'\0'结尾但默认隐藏所以【n+1】
//   char arr2[] = "abc";  // 自动计算数组大小为4
//   char arr3[3] = {'a', 'b', 'c'}; // 没有'\0'结尾
//   printf("%s\n", arr1);
//   printf("%s\n", arr2);
//   printf("%s\n", arr3); // 未以'\0'结尾，可能打印出乱码
//   char arr4[4] = {'a', 'b', 'c', '\0'}; // 手动添加'\0'结尾
//   printf("%s\n", arr4);                 // 正确打印abc
//   // 字符串结束的标志是'\0'
//   printf("%d\n", strlen(arr1)); // strlen计算字符串长度，不包括'\0'
//   return 0;
// }

// 8.转义字符
// int main() {
//   printf("Hello, World!\n");     //\n换行
//   printf("Hello, World!\t\n");   //\t水平制表符（tab键）
//   printf("Hello, \"World\"!\n"); //\"打印双引号
//   printf("Hello, \\World\\!\n"); //\\打印反斜杠
//   printf("Hello\0,World");       //\0字符串结束标志，后面的内容不打印
//   return 0;
// }

// 所有的转义字符：\? \' \" \\ \a \b \f \n \r \t \v \0 \ddd \xdd

// 9.注释
// 单行注释
/*
多行注释
*/

// 10.选择语句和循环语句
// 选择语句:if语句、switch语句

// int main() {
//   int input = 0;
//   printf("进入大学\n");
//   printf("要好好学习吗？(1-是 0-否)：");
//   scanf("%d", &input);
//   if (input == 1) {
//     printf("好offer\n");
//   } else {
//     printf("卖红薯\n");
//   }
//   return 0;
// }

// 循环语句:while语句、do-while语句、for语句

// int main() {
//   int line = 0;
//   printf("进入大学\n");
//   while (line < 20) {
//     printf("写代码:%d\n", line);
//     line++;
//   }
//   if (line >= 20) {
//     printf("好offer\n");
//   } else {
//     printf("继续加油\n");
//   }
//   return 0;
// }

// 11.函数
// 求两个任意整数的和

// 函数
// int Add(int x, int y) {
//   int z = 0;
//   z = x + y;
//   return z;
// }

// 简化
// int Add(int x, int y) { return x + y; }

// int main() {
//   int n1 = 0;
//   int n2 = 0;
//   // 输入
//   scanf("%d %d", &n1, &n2);
//   // 求和
//   // int sum = n1 + n2;
//   int sum = Add(n1, n2);
//   // 打印
//   printf("%d\n", sum);
//   return 0;
// }

// 12.数组
// int main() {
//   int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
//   // 数组的下标：  0   1   2   3   4   5   6   7   8   9（类比为房号）
//   // printf("%d\n",arr[8]);//通过下标访问数组元素，打印第9个元素90
//   // 打印整个数列：
//   int i = 0;
//   while (i < 10) {
//     printf("%d ", arr[i]);
//     i++;
//   }
//   return 0;
// }

// 13.操作符
// 算数操作符：+ - * / %
// 移位操作符：<< >>
// 位操作符：& ^ | ~
// 赋值操作符：= += -= *= /= %= &= ^= |= >>= <<=
// 单目操作符：!逻辑反操作 -负值 +正值 &取地址
// sizeof操作数的类型长度（以字节为单位）
//  ~对一个数的二进制按位取反 --前置、后置-- ++前置、后置++
//  *间接访问操作符（解引用操作符）（类型）强制类型转换
// 关系操作符：> >= < <= != ==
// 逻辑操作符：&& 逻辑与 || 逻辑或
// 条件操作符(三目操作符)：? :
// 如果条件为真则返回第一个操作数，否则返回第二个操作数 exp1(真) ? exp2(运行) :
// exp3(不运行) int main() {
//   int a = 0;
//   scanf("%d", &a);
//   int b = 10;
//   a > b ? printf("a>b") : printf("a<=b");
//   return 0;
// }

// 逗号运算符：,可以将多个表达式用逗号隔开，并将它们作为一个表达式来运算
// 特点：从左向右依次计算，整个表达式的结果是最后一个表达式的结果
// int main() {
//   int a = 10;
//   int b = 20;
//   int c = 0;
//   int d = (c = a - 2, a = b + c, c - 3);
//   printf("%d\n", d);
//   return 0;
// }

// 14.常见关键字
// auto break case char const continue default do double else enum
// extern float for goto if int long register return short signed
// sizeof static struct switch typedef union unsigned void volatile while

// 14.1.关键字typedef
// typedef unsigned int uint;
// typedef struct Node {
//   int data;
//   struct Node *next;
// } Node;

// int main() {
//   unsigned int num = 0;
//   uint num2 = 1;
//   struct Node n;
//   Node n2;
//   return 0;
// }

// 14.2.关键字static
// 修饰局部变量
// void test() {
//   static int a = 1;
//   a++;
//   printf("%d", a);
// }
// int main() {
//   int i = 0;
//   while (i < 10) {
//     test();
//     i++;
//   }
//   return 0;
// }

// static修饰局部变量的时候，局部变量出了作用域，不销毁
// 本质上，static修饰局部变量的时候，改变了变量的存储位置
// 局部变量=>全局变量
// 修饰全局变量
// extern int g_val;
// int main() {
//   printf("%d", g_val);
//   return 0;
// }

// static修饰全局变量的时候，这个全局变量的外部链接属性就变成了内部链接属性
// 其他源文件就不能再使用到这个全局变量了
// 修饰函数
// extern int Add(int x, int y);
// int main() {
//   int a = 10;
//   int b = 20;
//   int z = Add(a, b);
//   printf("%d", z);
//   return 0;
// }

// 一个函数本来是具有外部链接属性的，但是被static修饰的时候，它就变成了内部链接属性
// 其他源文件就不能再使用到这个函数了

// 15.#define定义常量和宏
// 15.1.define定义标识符常量
// #define NUM 100
// int main() {
//   printf("%d", NUM);
//   int n = NUM;
//   printf("%d", n);
//   int arr[NUM] = {0};
//   return 0;
// }

// 15.2.define定义宏
// 宏是有参数的宏，可以在宏定义中使用参数
// #define ADD // 宏名 (x, y)//宏的参数，参数是无类型 ((x) + (y))//宏体 //
// 宏定义 int Add(int x, int y) { return x + y; } // 函数定义 int main() {
//   int a = 10;
//   int b = 20;
//   int c = ADD(a, b);
//   printf("%d", c);
//   return 0;
// }

// 16.指针
// 16.1.内存地址
// int main() {
//   int a = 10;         // 向内存申请4个字节，存储10
//   &a;                 // 取地址操作符
//   printf("%p\n", &a); // 0x7fff7ee5a304//地址为第一个字节的地址
//   int *p = &a;        // p就是指针变量
//   int 说明指针指向的是一个int类型的变量（a是int类型） * 说明p是指针变量 *
//       p; //
//       解引用操作符，意思就是通过p中存放的地址，找到p所指向的对象，*p就是p指向的对象
//   *p = 20;
//   printf("%d\n", a);
//   printf("%p\n", p); // 0x7fff7ee5a304
//   char ch = 'a';
//   char *p1 = &ch;
//   printf("%p\n", p1);
//   return 0;
// }

// 16.2.指针变量的大小
// int main() {
//   printf("%zu\n", sizeof(int *));    // 8
//   printf("%zu\n", sizeof(char *));   // 8
//   printf("%zu\n", sizeof(double *)); // 8
//   printf("%zu\n", sizeof(float *));  // 8
//   printf("%zu\n", sizeof(long *));   // 8
//   printf("%zu\n", sizeof(short *));  // 8
//   //32位系统下，指针变量的大小是4字节，64位系统下，指针变量的大小是8字节
//   return 0;
// }

// 不管是什么类型的指针，都是在创建指针变量
// 指针变量是用来存放地址的
// 指针变量的大小取决与一个地址存放的时候需要多大的内存空间
// 32位机器上的地址：32bit位 - 4byte
// 64位机器上的地址：64bit位 - 8byte

// // 17.结构体
// struct Stu {
//   // 成员
//   char name[10];
//   int age;
//   char sex[10];
//   char tele[12];
// };
// void print(struct Stu *ps) {
//   printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).tele);
//   //->操作符：结构体指针变量->成员名
//   printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->tele);
// }
// int main() {
//   struct Stu s = {"张三", 18, "男", "13812345678"};
//   //.操作符：结构体变量.成员名
//   printf("%s %d %s %s\n", s.name, s.age, s.sex, s.tele);
//   print(&s);
//   return 0;
// }

// C语言初阶

// 1.语句
// 1.1.什么是语句
// 语句可以分为以下几类：表达式语句，函数调用语句，控制语句，复合语句，空语句
// 控制语句可以分为以下三类：
// 1.条件表达式也叫分支语句：if语句，switch语句
// 2.循环执行语句：do-while语句，while语句，for语句
// 3.转向语句：break语句，goto语句，continue语句，return语句
// while循环中的break适用于永久的终止循环，continue跳过本次循环后的代码，直接去判断部分，进行下一次循环的判断

// 2.分支语句(选择结构)
// 2.1.if语句
// int main() {
//   int a = 10;
//   if (a == 3) {
//     printf("hehe\n");
//   }
//   int age = 20;
//   if (age > 18) {
//     printf("成年\n");
//   }
//   int age1 = 10;
//   if (age1 < 18) {
//     printf("未成年\n");
//     printf("不能饮酒\n");
//   } else
//     printf("成年\n");
//   int age2 = 10;
//   scanf("%d", &age2);
//   if (age2 < 18)
//     printf("青少年\n");
//   else if (age2 >= 18 && age2 < 28)
//     printf("青年\n");
//   else if (age2 >= 28 && age2 < 40)
//     printf("中年\n");
//   else if (age2 >= 40 && age2 < 60)
//     printf("壮年\n");
//   else if (age2 >= 60 && age2 < 100)
//     printf("老年\n");
//   else
//     printf("不明\n");
//   return 0;
// }

// int test() {
//   int a = 4;
//   if (a == 4)
//     return 1;
//   return 0;
// }
// int main() {
//   int r = test();
//   printf("%d\n", r);
//   return 0;
// }

// 2.2.switch语句
// int main() {
//   int day = 0; // 必须为整型
//   scanf("%d", &day);
//   switch (day) {
//   case 1: // 必须为字符或者整型
//     printf("今天是周一\n");
//     break;
//   case 2:
//     printf("今天是周二\n");
//     break;
//   case 3:
//     printf("今天是周三\n");
//     break;
//   case 4:
//     printf("今天是周四\n");
//     break;
//   case 5:
//     printf("今天是周五\n");
//     break;
//   case 6:
//     printf("今天是周六\n");
//     break;
//   case 7:
//     printf("今天是周日\n");
//     break;
//   default:
//     printf("今天是其他\n");
//   }
//   return 0;
// }

// int main() {
//   int day = 0;
//   scanf("%d", &day);
//   switch (day) {
//   case 1:
//   case 2:
//   case 3:
//   case 4:
//   case 5:
//     printf("weekday\n");
//     break;
//   case 6:
//   case 7:
//     printf("weekend\n");
//     break;
//   default:
//     printf("error\n");
//     break;
//   }
//   return 0;
// }

// switch语句的嵌套：
// int main() {
//   int n = 0;
//   int m = 0;
//   switch (n) {
//   case 1:
//     m++;
//   case 2:
//     n++;
//   case 3:
//     switch (n) {
//     case 1:
//       n++;
//     case 2:
//       m++;
//       n++;
//       break;
//     }
//   case 4:
//     m++;
//     break;
//   default:
//     break;
//   }
//   printf("m=%d,n=%d\n", m, n);
//   return 0;
// }

// 3.循环语句
