#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
  int x[] = {1, 2, 3, 4, 7};
  printf("%" PRIi16 "\n",
         (int16_t)INT16_MAX);

  printf("%" PRIu64 "\n", UINT64_MAX);
  printf("%td\n", PTRDIFF_MAX);

  intptr_t p = x;
  printf("%p %p\n", p, x);

  p = x[0];
  printf("%ld\n", p);
}
