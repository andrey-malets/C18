#include <stddef.h>
#include <stdio.h>

struct card {
  unsigned short cvc;
  unsigned number[4];
  unsigned char validity[2];
};

int main(void) {
  struct card c;
  printf("%lu\n", sizeof(c));
  printf("%lu %lu %lu\n",
    offsetof(struct card, cvc),
    offsetof(struct card, number),
    offsetof(struct card, validity));
}
