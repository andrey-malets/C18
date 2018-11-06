#include <math.h>

int solve_qe(
    float a, float b, float c,
    float *x1, float *x2) {
  if (a == 0.f) {
    *x1 = *x2 = -c / b;
    return 1;
  }

  float d = b * b - 4 * a * c;
  if (d < 0.f)
    return 0;

  *x1 = (-b + sqrt(d)) / 2.f / a;
  *x2 = (-b - sqrt(d)) / 2.f / a;
  return 1;
}
