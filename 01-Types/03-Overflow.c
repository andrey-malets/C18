#include <stdio.h>

int main(void) {
  unsigned int x = 1 << 31;
  unsigned int y = x;

  long l1 = (1LL << 31) - 1;
  int x1 = l1;
  int y1 = x1;

  printf("%u\n", x + y);
  printf("%d\n", x1 + y1);
}
