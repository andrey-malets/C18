#include <inttypes.h>
#include <stdio.h>

#define BIG_NUMBER 100500ULL
#define PRINT_NUMBER(number) printf("%llu\n", big_number)

int main(void) {
  /* The biggest unsigned
   * 64-bit number */
  uint64_t big_number = BIG_NUMBER;

  PRINT_NUMBER(big_number);
}
