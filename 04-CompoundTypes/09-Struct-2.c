#include <stdio.h>

struct point {
  int x;
  int y;
};

struct segment {
  struct point begin;
  struct {int x; int y;} end;
};

int main(void) {
  struct point p = {10, 20};
  struct segment s1 = {
    {1, 2}, {.y = 4, .x = 3}};

  struct segment s2 = s1;
  printf("%d %d\n",
         s1.begin.x, s1.end.y);
  s1.begin = p;
  printf("%d %d\n",
         s2.begin.x, s2.end.y);
}
