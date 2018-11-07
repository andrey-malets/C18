#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  srand(20181107u);
  for (size_t i = 0; i != 10000; ++i) {
    int x = rand();
    assert((sin(x) * sin(x) + cos(x) * cos(x) - 1.) < 1e-5);

    int y = x % 10;
    assert(((cosh(y) * cosh(y) - sinh(y) * sinh(y)) - 1.) < 1e-5);
  }
}
