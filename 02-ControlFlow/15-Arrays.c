#include <stdio.h>
#include <stdlib.h>

int main(void) {
  const size_t size = 10;
  int x[] = {1, 3, 3, 7};
  int y[size];

  for (size_t i = 0;
       i != sizeof(x) / sizeof(x[0]);
       ++i) {
    y[i] = x[i] * 2;
  }

  for (size_t i = 0; i != size; ++i) {
    printf("%d%c", y[i],
           i == size - 1 ? '\n' : ' ');
  }
}
