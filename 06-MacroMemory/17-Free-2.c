#include <stdio.h>
#include <stdlib.h>

void print(int *x) {
  int *p = x;
  for (; *p; ++p)
    printf("%d ", *p);
  printf("\n");

  free(p);
}

int main(void) {
  int *x = malloc(5 * sizeof(*x));
  x[4] = 0;
  print(x);

  int *y = x;
  y[4] = 0;
  print(y);
}
