#include <stdio.h>

int gcd(int a, int b) {
  return (b && a) ? gcd(b, a % b) : a;
}

int main(void) {
  printf("%d\n", gcd(120, 48));
}
