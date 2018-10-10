#include <stdio.h>

struct point {
  int x;
  int y;
};

int main(void) {
  struct point p;
  scanf("%d %d\n", &p.x, &p.y);
  p.x *= 2;
  p.y = p.y + 1;
  printf("%d %d\n", p.x, p.y);
}
