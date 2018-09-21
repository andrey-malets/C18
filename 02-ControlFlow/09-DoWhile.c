#include <stdio.h>

int main(void) {
  int a = 120, b = 48;

  do {
    int x = b;
    b = a % b;
    a = x;
  } while (b && a);

  printf("%d\n", a);
}
