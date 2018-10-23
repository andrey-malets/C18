#include <stdio.h>
#include <stdlib.h>

int *sum(int x, int y) {
  int *rv = malloc(sizeof(int) * 1000);
  for (size_t i = 0; i != 1000; ++i)
    rv[i] = x + y + i;
  return rv;
}

int main(void) {
  for (size_t i = 0; i != 10000000000; ++i)
    printf("%d\n", *sum(i, i));
}
