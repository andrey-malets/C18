#include <stdio.h>

int main(void) {
  float x = 0.0001f, y = 1000.0f;

  float sum = 0.0f;
  for (size_t i = 0; i != 1000; ++i)
    sum += x;

  printf("%f %f %d\n", x * y, sum, x * y == sum);
}
