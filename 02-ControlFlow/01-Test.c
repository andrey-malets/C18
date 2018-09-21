#include <stdlib.h>

int f(int x[], size_t len) {
  return x[0];
}

int main(void) {
  int x[] = {1, 2, 3};
  if (int y = x[0]) {
    return 0;
  }
  return 1;
}
