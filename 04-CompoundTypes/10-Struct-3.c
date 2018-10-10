#include <stdio.h>

struct point {
  int x;
  int y;
};

struct triangle {
  struct point points[3];
};

struct triangle mirror_x(
    struct triangle t) {
  t.points[0].y = -t.points[0].y;
  t.points[1].y = -t.points[1].y;
  t.points[2].y = -t.points[2].y;
  return t;
}

void mirror_y(struct triangle *t) {
  t->points[0].x = -t->points[0].x;
  t->points[1].x = -t->points[1].x;
  t->points[2].x = -t->points[2].x;
}

int main(void) {
  struct triangle t1 = {
    {{0, 0}, {3, 0}, {0, 4}}
  };
  struct triangle t2 = mirror_x(t1);

  printf("%d %d\n",
         t1.points[1].x,
         t1.points[2].y);
  printf("%d %d\n",
         t2.points[1].x,
         t2.points[2].y);

  mirror_y(&t2);
  printf("%d %d\n",
         t2.points[1].x,
         t2.points[2].y);
}
