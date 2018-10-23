#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *xs = calloc(10, sizeof(xs[0]));
  xs[9] = 10;

  printf("%p %d\n", (void*)xs, xs[0]);
  printf("%p %d\n", (void*)xs, xs[9]);

  free(xs);
}
