#include <stdio.h>

int f(int x[], size_t len) {
  int prod = 1;
  for (size_t i = 0; i != len; ++i) {
    prod *= x[i];
  }
  return prod;
}

int g(int x[][3], size_t len) {
  int prod = 1;
  for (size_t i = 0; i != len; ++i) {
    prod *= x[i][1];
  }
  return prod;
}

int main(void) {
  int x[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int y[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  printf("%d\n", g(x, sizeof(x) /
                      sizeof(x[0])));
  printf("%d\n", f(x[0], sizeof(x[0]) /
                         sizeof(x[0][0])));
}
