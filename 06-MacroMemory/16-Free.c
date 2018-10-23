#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *x = calloc(10, sizeof(*x));

  for (size_t i = 0; i != 10; ++i)
    x[i] = 10 - 1 - i;

  while(*x)
    printf("%d\n", *x++);

  free(x);
}
