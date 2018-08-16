#include <stdio.h>

int main(void) {
  unsigned int x = 5, y = 2;
  int x1 = 5, y1 = -2;

  printf("%u\n", x / y);
  printf("%d\n", x1 / y1);
  printf("%d\n", x1 % y1);
  printf("%d\n", (x1 / y1) * y1 + (x1 % y1));
}
