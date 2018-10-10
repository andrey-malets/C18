#include <inttypes.h>
#include <stdio.h>

int main(void) {
  uint32_t x[] = {1, 2, 3, 4, 5};
  uint64_t y[] = {1, 2};

  void *pv1 = &x, *pv2 = &y;
  printf("%u %llu\n", x[0], y[1]);
  printf("%u %llu\n",
         ((uint32_t *)pv2)[0],
         ((uint64_t *)pv1)[1]);
}
