#include <stddef.h>
#include <stdio.h>

struct card {
  short num[4];
  unsigned valid_month: 4;
  unsigned valid_year: 7;
  unsigned cvc : 10;
};

int main(void) {
  struct card c = {{4817, 7601, 8003, 3470}, 9, 19, 356};
  printf("%d %d %d %d, %d/%d, %d\n",
         c.num[0], c.num[1], c.num[2], c.num[3],
         c.valid_month, c.valid_year, c.cvc);

  printf("%lu\n", sizeof(c));
  // printf("%lu\n", offsetof(struct card, cvc));
}
