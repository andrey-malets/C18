#include <stdio.h>

int main(void) {
  int i = -1;
  unsigned int ui = 1;

  short int s = -20;
  unsigned short us = 10;

  char c = 'A';

  printf("%d\n", i);
  printf("%u\n", ui);
  printf("%d\n", i - ui);

  printf("%hd\n", s);
  printf("%hu\n", us);

  printf("%c\n", c);
  printf("%d\n", c);

  printf("%lu\n", sizeof(i));
  printf("%lu\n", sizeof(s));
  printf("%lu\n", sizeof(c));

  return 0;
}
