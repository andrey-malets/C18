#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
  /* The biggest unsigned
   * 64-bit number */
  uint64_t big_number = UINT64_MAX;

  printf("%llu\n", big_number);
}
