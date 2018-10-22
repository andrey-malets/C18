#include <inttypes.h>
#include <stdio.h>

#define MAX(a, b) a < b ? b : a
#define DOUBLE(x) x << 1

int main(void) {
  uint64_t a = 100, b = 101;

  printf("%llu\n", MAX(a, b));
  printf("%llu\n", MAX(++a, b));
  printf("%llu\n", MAX(a, b));

  uint64_t x = 200;

  printf("%llu\n", DOUBLE(x));
  // printf("%llu\n", DOUBLE(x) + 1);
}
