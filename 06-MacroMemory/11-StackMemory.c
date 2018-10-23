#include <stdio.h>

int f(int x, int y) {
  return x + y;
}

int main(void) {
  int x = 10, y = 20, z;
  printf("%d %d\n", f(x, y), z);
  printf("%d %d\n", f(x, y), z);
}
