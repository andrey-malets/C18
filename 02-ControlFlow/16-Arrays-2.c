#include <stdio.h>
#include <stdlib.h>

void double_array(int x[]) {
  for (size_t i = 0;
       i != sizeof(x) / sizeof(x[0]);
       ++i) {
    x[i] = x[i] * 2;
  }
}

int main(void) {
  const size_t size = 10;
  int x[] = {1, 3, 3, 7};

  double_array(x);

  for (size_t i = 0; i != size; ++i) {
    printf("%d%c", x[i],
           i == size - 1 ? '\n' : ' ');
  }
}

