#include "point.h"

struct point *init_point(void *memory, int x, int y) {
  struct point *p = memory;
  p->x = x;
  p->y = y;
  return p;
}

double distance(const struct point *p1,
                const struct point *p2) {
  unsigned squared_distance =
      (p2->x - p1->x) * (p2->x - p1->x) +
      (p2->y - p1->y) * (p2->y - p1->y);
  double value = sqrt(squared_distance);
  return value;
}
