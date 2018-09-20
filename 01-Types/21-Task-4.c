#include <math.h>

int main(void) {
  const float arg = 1.04719;
  const float arg_sq = arg * arg;

  float sin_value =
      arg -
      arg * arg_sq / 6. +
      arg * arg_sq * arg_sq / 120.;
  float cos_value =
      1 -
      arg_sq / 2. +
      arg_sq * arg_sq / 24.;

  float value = sin_value * sin_value + cos_value * cos_value;

  return value == 1;
}
