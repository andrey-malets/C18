#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

static_assert(sizeof(intptr_t) >= sizeof(int),
              "size of intptr_t is less than size of int!");
static_assert(sizeof(intptr_t) >= sizeof(void *),
              "size of intptr_t is less than size of a ptr!");

int main(void) {

  int x[] = {1, 2, 3, 4, 7};
  printf("%" PRIi16 "\n",
         (int16_t)INT16_MAX);

  printf("%" PRIu64 "\n", UINT64_MAX);
  printf("%td\n", (ptrdiff_t)PTRDIFF_MAX);

  intptr_t p = (intptr_t)x;
  printf("%p %p\n", (void *)p, (void *)x);

  p = x[0];
  printf("%ld\n", p);
}
