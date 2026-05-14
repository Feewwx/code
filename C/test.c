#include <stdio.h>

int main() {
  int a = 0;
  while (1) {
    int b = 0;
    int c = 0;
    scanf("%d", &a);
    while (b < 10) {
      b = a / 10;
      c++;
    }
    for (int i = 0; i < c; i++) {
      b = b * 10;
    }
    a = a - b;
    printf("%d ", b);
  }
  return 0;
}
