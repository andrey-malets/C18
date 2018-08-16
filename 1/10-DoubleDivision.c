#include <stdio.h>

int main(void) {
  double x = 0.0001, y = 1000.0;

  double sum = 0.0f;
  for (size_t i = 0; i != 1000; ++i)
    sum += x;

  printf("%lf %lf %d\n", x * y, sum, x * y == sum);
}
