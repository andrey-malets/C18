#include <stdio.h>

int main(void) {
  float f = -5.6f;
  int i = f;

  printf("%d\n", i);
  printf("%f\n", f);
  printf("%f\n", 10 * (f / 10));
}
