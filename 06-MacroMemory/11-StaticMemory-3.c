#include <stdio.h>

int count(int x) {
  static int y;
  return y += x;
}

int main(void) {
  printf("%d\n", count(1));
  printf("%d\n", count(2));
  printf("%d\n", count(3));
}
