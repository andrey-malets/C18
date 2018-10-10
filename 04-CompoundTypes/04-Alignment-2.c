#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int main(int ac, char *av[]) {
  const size_t SIZE = 100 * 1000 * 1000;
  char *a = malloc(SIZE);
  if (!a)
    return 1;

  size_t align = 0;
  sscanf(av[1], "%zu", &align);

  for (size_t i = 0; i < SIZE; ++i)
    a[i] = i;

  int64_t x = 0;
  for (size_t i = align; i < SIZE - sizeof(x);
       i += sizeof(int64_t))
    x += *(int64_t *)&a[i];

  printf("%lld\n", x);
  free(a);
}
