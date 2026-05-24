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

#include <stdio.h>

int main() {
  int arr[3][4] = {0};

  printf("%p\n", arr);     // 0x7ffe950eec50
  printf("%p\n", arr + 1); // 0x7ffe950eec60

  printf("%d\n", sizeof(arr));                        // 48
  printf("%d\n", sizeof(arr[0]));                     // 16
  printf("%d\n", sizeof(arr[0][0]));                  // 4
  printf("%d\n", sizeof(arr) / sizeof(arr[0]));       // 3
  printf("%d\n", sizeof(arr[0]) / sizeof(arr[0][0])); // 4

  return 0;
}
