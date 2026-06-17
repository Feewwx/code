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

#include <stdio.h>

int main() {
  int arr[10] = {0};
  int sz = sizeof(arr) / sizeof(arr[0]);
  char arr1[10] = {'a'};
  int sz1 = sizeof(arr1) / sizeof(arr1[0]);
  printf("%d", sz);
  printf("%d", sz1);
  return 0;
}
