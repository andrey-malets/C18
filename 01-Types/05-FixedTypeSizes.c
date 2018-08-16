#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint64_t x = 1 << 31, y = x;
  printf("%" PRIu64 "\n", (x + y) / 2);
}
