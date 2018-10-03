#include <stdio.h>

int main(void) {
  int x = 10, y = 20;
  int *const p = &x;
  const int *const q = &y;
  printf("%p %d %d\n", p, *p, x);
  *p = 30;
  printf("%p %d %d\n", p, *p, x);
  // p = &y;
  // q = &x;
  // *q = 50;
}
