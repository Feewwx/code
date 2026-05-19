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

#include <stdio.h>

void feewwx(int *A, int a, int *B, int *C) {
  int d = 1;
  while (1) {
    if (A[a] != 0) {
      B[1] = A[d];
      d++;
    } else
  }
  return feewwx(A, a - 1, B, C);
}

int main() {
  int a = 0; // 圆盘的数量
  scanf("%d", &a);
  int A[10086] = {0};
  int B[10086] = {0};
  int C[10086] = {0};
  for (int i = 0; i < a; i++) {
    A[i] = i;
  }
  feewwx(A, a, B, C);
  return 0;
}
