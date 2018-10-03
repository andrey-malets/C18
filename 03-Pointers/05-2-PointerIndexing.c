#include <stdio.h>

int sum1(int p[], size_t len) {
  int result = 0;
  for (int *pp = p; pp - p != len; ++pp) {
    result += *pp;
  }
  return result;
}

int sum2(int p[], size_t len) {
  int result = 0;
  for (size_t i = 0; i != len; ++i) {
    result += p[i];
  }
  return result;
}

int main(void) {
  int x[] = {1, 2, 3, 4, 5};
  const size_t len =
      sizeof(x) / sizeof(x[0]);
  printf("%d %d\n", sum1(x, len), sum2(x, len));
}
