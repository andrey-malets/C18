#include <math.h>
#include <stdio.h>

int main(void) {
  float x = 10.f;

  if (fabs(x) < 1e-5)
    goto failure;

  float y = 1.f / x;
  if (y < 0)
    goto failure;

  printf("%f\n", sqrt(y));
  return 0;

failure:
  fputs("shit", stderr);
}
