// #include <stdio.h>

// int main() {
//   int a = 0;
//   scanf("%d", &a);
//   while (1) {
//     int b = 0;
//     int c = 0;
//     if (b == 0)
//       b = a / 10;
//     while (b > 10) {
//       b = b / 10;
//       c++;
//     }
//     if (a > 10)
//       printf("%d ", b);
//     else {
//       printf("%d ", a);
//       return 0;
//     }
//     for (int i = 0; i <= c; i++) {
//       b = b * 10;
//     }
//     a = a - b;
//     if (b < 10)
//       return 0;
//   }
// }

// void print(unsigned int n) {
//   if (n > 9) {
//     print(n / 10);
//   }
//   printf("%d", n % 10);
// }
//
// int main() {
//   unsigned int num = 0;
//   scanf("%d", &num);
//   print(num);
//   return 0;
// }

// int my_strlen(char *str) {
//   if (*str != '\0')
//     return 1 + my_strlen(str + 1);
//   else
//     return 0;
// }
//
// int main() {
//   char arr[] = "abc";
//   int len = my_strlen(arr);
//   printf("%d\n", len);
//   return 0;
// }

// #include <stdio.h>
//
// void feewwx(int *A, int a, int *B, int *C) {
//   int d = 1;
//   while (1) {
//     if (A[a] != 0) {
//       B[1] = A[d];
//       d++;
//     } else
//   }
//   return feewwx(A, a - 1, B, C);
// }
//
// int main() {
//   int a = 0; // 圆盘的数量
//   scanf("%d", &a);
//   int A[10086] = {0};
//   int B[10086] = {0};
//   int C[10086] = {0};
//   for (int i = 0; i < a; i++) {
//     A[i] = i;
//   }
//   feewwx(A, a, B, C);
//   return 0;
// }

// #include <stdio.h>
//
// int main() {
//   int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 4; j++) {
//       printf("%d ", arr[i][j]);
//     }
//     printf("\n");
//   }
//   return 0;
// }

// #include <stdio.h>
//
// int main() {
//   int arr[10] = {0};
//
//   printf("%p\n", arr); // 首元素地址
//   printf("%p\n", arr + 1);
//
//   printf("%p\n", &arr[0]); // 首元素地址
//   printf("%p\n", &arr[0] + 1);
//
//   printf("%p\n", &arr); // 数组地址
//   printf("%p\n", &arr + 1);
//
//   int n = sizeof(arr);
//   printf("%d\n", n);
//
//   return 0;
// }

// #include <stdio.h>
//
// int main() {
//   int arr[3][4] = {0};
//   printf("%p\n", arr);
//   printf("%p\n", arr + 1);
//   return 0;
// }

// #include <stdio.h>
//
// int main() {
//   int arr[3][4] = {0};
//
//   printf("%p\n", arr);     // 0x7ffe950eec50
//   printf("%p\n", arr + 1); // 0x7ffe950eec60
//
//   printf("%d\n", sizeof(arr));                        // 48
//   printf("%d\n", sizeof(arr[0]));                     // 16
//   printf("%d\n", sizeof(arr[0][0]));                  // 4
//   printf("%d\n", sizeof(arr) / sizeof(arr[0]));       // 3
//   printf("%d\n", sizeof(arr[0]) / sizeof(arr[0][0])); // 4
//
//   return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>
//
// int main() {
//   char out_arr[11][11];
//   char in_arr[11][11];
//
//   memset(in_arr, '0', sizeof(in_arr));
//   memset(out_arr, '#', sizeof(out_arr));
//
//   srand(time(NULL));
//   for (int i = 0; i < 10; i++) {
//     int x = rand() % 9 + 1;
//     int y = rand() % 9 + 1;
//     if (in_arr[x][y] == '0') {
//       in_arr[x][y] = '1';
//     } else {
//       i--;
//     }
//   }
//
//   printf("**********************************\n");
//   printf("********  1.play  0.exit  ********\n");
//   printf("**********************************\n");
//
//   int a = 0;
//   int win = 0;
//   printf("请选择:>");
//   scanf("%d", &a);
//   if (a == 1) {
//
//     for (int i = 0; i < 10; i++) {
//       printf("%d  ", i);
//     }
//     printf("\n");
//
//     for (int i = 1; i < 10; i++) {
//       printf("%d  ", i);
//       for (int j = 1; j < 10; j++) {
//         printf("%c  ", in_arr[i][j]);
//       }
//       printf("\n");
//     }
//
//     printf("\n");
//     printf("\n");
//
//     for (int i = 0; i < 10; i++) {
//       printf("%d  ", i);
//     }
//     printf("\n");
//
//     for (int i = 1; i < 10; i++) {
//       printf("%d  ", i);
//       for (int j = 1; j < 10; j++) {
//         printf("%c  ", out_arr[i][j]);
//       }
//       printf("\n");
//     }
//     printf("\n");
//     while (1) {
//       printf("请输入坐标");
//       int x = 0;
//       int y = 0;
//       scanf("%d%d", &y, &x);
//       if (x > 10 || x < 1 || y > 10 || y < 1) {
//         printf("请输入正确的坐标");
//         return 0;
//       } else if (in_arr[x][y] == '1') {
//         printf("game over");
//         return 0;
//       } else {
//         int a = in_arr[x + 1][y + 1] + in_arr[x][y + 1] + in_arr[x - 1][y +
//         1] +
//                 in_arr[x + 1][y] + in_arr[x - 1][y] + in_arr[x + 1][y - 1] +
//                 in_arr[x][y - 1] + in_arr[x - 1][y - 1];
//         out_arr[x][y] = a - 8 * '0' + '0';
//       }
//       for (int i = 0; i < 10; i++) {
//         printf("%d  ", i);
//       }
//       printf("\n");
//
//       for (int i = 1; i < 10; i++) {
//         printf("%d  ", i);
//         for (int j = 1; j < 10; j++) {
//           printf("%c  ", out_arr[i][j]);
//         }
//         printf("\n");
//       }
//       printf("\n");
//       win++;
//       if (win == 71) {
//         printf("you win");
//         return 0;
//       }
//     }
//   } else if (a == 0) {
//     return 0;
//   } else {
//     printf("请输入正确的数字");
//     return 0;
//   }
//   return 0;
// }

// #include <stdio.h>
// int main() {
//   int a = 3;
//   int b = -5;
//   printf("%d\n", a ^ b); // -8
//   return 0;
// }

// #include <stdio.h>
// #include <string.h>
//
// struct Stu {
//   char name[20];
//   int age;
//   double score;
// };
//
// void set_stu(struct Stu *s) {
//   // strcpy((*s).name, "zhangsan");
//   // (*s).age = 20;
//   // (*s).score = 100.0;
//   strcpy(s->name, "zhangsan");
//   s->age = 20;
//   s->score = 100.0;
// }
//
// void print_stu(struct Stu s) { printf("%s %d %.1f\n", s.name, s.age,
// s.score); }
//
// int main() {
//   struct Stu s = {0};
//   set_stu(&s);
//   print_stu(s);
//   return 0;
// }

// #include <stdio.h>
//
// int main() {
//   int a = 0x11223344;
//   int *pa = &a; // p是指针变量
//   *pa = 0;      // 解引用操作符
//   char *pc = (char *)pa;
//   *pc = 0; // 只改变了第一个地址
//   printf("pa = %p\n", pa);
//   printf("pa + 1 = %p\n", pa + 1);
//   printf("pc = %p\n", pc);
//   printf("pc + 1 = %p\n", pc + 1);
// }

// #include <stdio.h>
//
// int main() {
//   int arr[10] = {0};
//   int sz = sizeof(arr) / sizeof(arr[0]);
//   char arr1[10] = {'a'};
//   int sz1 = sizeof(arr1) / sizeof(arr1[0]);
//   printf("%d", sz);
//   printf("%d", sz1);
//   return 0;
// }

// #include <stdio.h>
// struct Peo {
//   char name[10];
//   char tele[12];
//   char sex[5];
//   int age;
// };
//
// struct St {
//   char name[10];
//   char tele[12];
//   char sex[5];
//   int age;
// };
//
// void print1(struct Peo p) {
//   printf("%s %s %s %d\n", p.name, p.tele, p.sex, p.age);
// }
//
// void print2(struct St *s) {
//   printf("%s %s %s %d\n", s->name, s->tele, s->sex, s->age);
// }
//
// int main() {
//   struct Peo p = {"zhangsan", "13800138000", "男", 20};
//   struct St s = {"lisi", "13800138000", "男", 20};
//
//   print1(p);
//   print2(&s);
//
//   return 0;
// }
// #include <stdio.h>
//
// int main() {
//   int n = 9;
//   float *pFloat = (float *)&n;
//   printf("n的值为:%d\n", n);
//   printf("pFloat的值为:%f\n", *pFloat);
//   *pFloat = 9.0;
//   printf("n的值为:%d\n", n);
//   printf("*pFloat的值为:%f\n", *pFloat);
//   return 0;
// }

// #include <stdio.h>
// int main() {
//   const char *p1 = "abc";
//   const char *p2 = "abc";
//   char *p3 = "abc";
//   char *p4 = "abc";
//   char arr5[] = "abc";
//   char arr6[] = "abc";
//   char *p5 = arr5;
//   char *p6 = arr6;
//   if (p1 == p2)
//     printf("ok");
//   else
//     printf("no");
//   if (p3 == p4)
//     printf("ok");
//   else
//     printf("no");
//   if (p5 == p6)
//     printf("ok");
//   else
//     printf("no");
//   return 0;
// }

// #include <stdio.h>
//
// int main() {
//   int arr[10] = {0};
//   printf("%p\n", arr);
//   printf("%p\n", arr + 1);
//
//   printf("%p\n", &arr[0]);
//   printf("%p\n", &arr[0] + 1);
//
//   printf("%p\n", &arr);
//   printf("%p\n", &arr + 1);
//
//   int (*p)[10] = &arr;
//
//   int sz = sizeof(arr);
//   printf("%d\n", sz);
//   return 0;
// }

// typedef void (*pf_t)(int);
//
// int main() {
//   (*(void (*)())0)();
//   void (*signal(int, void (*)(int)))(int);
//   pf_t signal(int, pf_t);
//   return 0;
// }

// #include <stdio.h>
//
// void menu() {
//   printf("**********************************\n");
//   printf("********  1.add  2.sub  **********\n");
//   printf("********  3.mul  4.div  **********\n");
//   printf("***********  0.exit  *************\n");
//   printf("**********************************\n");
// }
//
// int Add(int x, int y) { return x + y; }
//
// int Sub(int x, int y) { return x - y; }
//
// int Mul(int x, int y) { return x * y; }
//
// int Div(int x, int y) { return x / y; }
//
// void calc(int (*pf)(int, int)) {
//   int x = 0;
//   int y = 0;
//   int ret = 0;
//
//   printf("请输入2个操作数:>");
//   scanf("%d %d", &x, &y);
//   ret = pf(x, y);
//   printf("%d\n", ret);
// }
//
// int main() {
//   int input = 0;
//   // int x = 0;
//   // int y = 0;
//   // int ret = 0;
//
//   do {
//     menu();
//     printf("请选择:>");
//     scanf("%d", &input);
//     // printf("请输入2个操作数:>");
//     // scanf("%d %d", &x, &y);
//     // 如果想退出或者输入错误,不能直接退出,必须先输入两个操作数才能退出,很怪
//     // 解决方法:把输入两个操作数的步骤塞入case里
//
//     switch (input) {
//     case 1:
//       // printf("请输入2个操作数:>");
//       // scanf("%d %d", &x, &y);
//       // ret = Add(x, y);
//       // printf("%d\n", ret);
//       calc(Add);
//       break;
//     case 2:
//       // printf("请输入2个操作数:>");
//       // scanf("%d %d", &x, &y);
//       // ret = Sub(x, y);
//       // printf("%d\n", ret);
//       calc(Sub);
//       break;
//     case 3:
//       // printf("请输入2个操作数:>");
//       // scanf("%d %d", &x, &y);
//       // ret = Mul(x, y);
//       // printf("%d\n", ret);
//       calc(Mul);
//       break;
//     case 4:
//       // printf("请输入2个操作数:>");
//       // scanf("%d %d", &x, &y);
//       // ret = Div(x, y);
//       // printf("%d\n", ret);
//       calc(Div);
//       break;
//
//       // 新问题:代码太过冗余,难维护
//       // 解决方法:函数指针
//
//     case 0:
//       printf("已退出\n");
//       break;
//     default:
//       printf("输入错误\n");
//       break;
//     }
//   } while (input);
//   return 0;
// }
