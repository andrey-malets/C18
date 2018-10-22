#include <math.h>
#include <stdio.h>

#define CHECK_OR_GOTO(label, cond) \
   if (!(cond)) goto label

int main(void) {
  float x = 10.f;

  CHECK_OR_GOTO(failure, fabs(x) > 1e-5);

  float y = 1.f / x;
  CHECK_OR_GOTO(failure, y >= 0);

  printf("%f\n", sqrt(y));
  return 0;

failure:
  fputs("shit", stderr);
}
