#include <stdio.h>

int main(void) {
  int x[] = {1, 2, 3};
  int *p = &x[0];
  int **pp = &p;

  printf("%2d %2d %p %2d\n",
         x[0], *p, (void *)*pp, **pp);
  **pp = 10;
  printf("%2d %2d %p %2d\n",
         x[0], *p, (void *)*pp, **pp);
  *pp = &x[1];
  printf("%2d %2d %p %2d\n",
         x[0], *p, (void *)*pp, **pp);
}
