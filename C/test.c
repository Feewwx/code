#include <stdio.h>

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
