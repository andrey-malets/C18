#include <stdio.h>

struct one_of {
  union {
    int x;
    long y;
  };
};

int main(void) {
  struct one_of s;
  s.x = 10;
  printf("%ld\n", s.y);
}
