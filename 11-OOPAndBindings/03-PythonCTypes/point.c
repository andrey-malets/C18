#include "point.h"

struct point *init_point(void *memory, int x, int y) {
  struct point *p = memory;
  p->x = x;
  p->y = y;
  return p;
}
