#include <stddef.h>
#include <stdio.h>

int main(void) {
  int x[] = {1, 2, 3, 4, 7};

  ptrdiff_t fwd = &x[0] - &x[4];
  ptrdiff_t rev = &x[4] - &x[0];

  printf("%ld %ld", fwd, rev);
}
