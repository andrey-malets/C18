#include <math.h>
#include <stdio.h>

int main(void) {
  const float eps = 1e-6f;
  float a = 42.f;

  float x0 = 7.f, x1;

  do {
    x1 = x0;
    x0 = (x0 * x0 + a) / (2.f * x0);
  } while (fabs(x1 - x0) > eps);

  printf("%f %f\n", x1 * x1, a);
}
