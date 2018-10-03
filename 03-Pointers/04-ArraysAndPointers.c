#include <stdio.h>
#include <stdlib.h>

void double_array(int *x, size_t len) {
  for (size_t i = 0; i != len; ++i) {
    *(x + i) = *(x + i) * 2;
  }
}

int main(void) {
  const size_t size = 10;
  int x[] = {1, 3, 3, 7};
  int *p = x;
  // x = p;

  double_array(x, sizeof(x) / sizeof(x[0]));
  double_array(p, sizeof(p) / sizeof(p[0]));

  for (size_t i = 0; i != size; ++i) {
    printf("%d%c", p[i],
           i == size - 1 ? '\n' : ' ');
  }
}
