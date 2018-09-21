#include <math.h>
#include <stdio.h>

int main(void) {
  float x = 0.f, y = NAN;

  if (fabs(x) < 1e-5) {
    goto failure;
  }
  y = -1.f / x;
  if (y < 0) {
    goto failure;
  }
  printf("%f\n", sqrt(y));
  return 0;

failure:
  fputs("error:\n", stderr);
  fprintf(stderr, " X = %f\n", x);
  fprintf(stderr, " Y = %f\n", y);
}
