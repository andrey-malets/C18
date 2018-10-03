#include <stdio.h>

int main(void) {
  int x[] = {1, 2, 3, 4, 5};
  int *p1 = &x[0], *p2 = &3[x];
  printf("%d %d\n", *p1, *p2);
  printf("%td\n", p1 - p2);
  printf("%d\n", *p1 - *p2);
  printf("%d\n", p2 == p1 + 3);
  printf("%d %d\n", x[1], 1[x]);
  printf("%d %d\n", *(x + 1), *(1 + x));
}
