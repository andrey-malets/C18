#include <math.h>

int main(void) {
  double a = 1, b = 3, c = -100500;
  float d = sqrt(b * b - 4 * a * c);

  float x1 = (-b + d) / 2 / a;
  float x2 = (-b - d) / 2 / a;

  return a * (x1 * x1) + b * x1 + c == 0,
         a * (x2 * x2) + b * x2 + c == 0;
}
