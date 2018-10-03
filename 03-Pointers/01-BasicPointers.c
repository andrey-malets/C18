#include <stdio.h>

int main(void) {
  int x = 10;
  int *p = &x;
  printf("%p %lu %lu\n", p, sizeof(p),
         sizeof(*p));
  printf("%p %d %d\n", p, *p, x);
  *p = 20;
  printf("%p %d %d\n", p, *p, x);
  x = 30;
  printf("%p %d %d\n", p, *p, x);
}
