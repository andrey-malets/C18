#include <stdio.h>

int main(void) {
  int x, y;

  while (x + y != 7) {
    ++y, ++x;
    ++x;
  }

  printf("%d %d\n", x, y);
}
