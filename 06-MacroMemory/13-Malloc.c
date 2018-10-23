#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *x = malloc(sizeof(x));
  *x = 0;

  int *xs = malloc(10);
  xs[10] = 10;

  printf("%p %d\n", (void*)x, *x);
  printf("%p %d\n", (void*)xs, xs[10]);

  free(xs);
  free(x);
}
