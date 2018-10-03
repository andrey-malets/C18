#include <stdio.h>

int main(void) {
  int x = 10, y = 20;
  const int z = 30;
  const int *p = &x;
  // int *q = &z;

  p = &y;
  // *p = 50;
  printf("%p %d %d\n", p, *p, x);
}
