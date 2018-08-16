#include <stdio.h>

int main(void) {
  long x = 1 << 31, y = x;
  printf("%lu\n", (x + y) / 2);
}
