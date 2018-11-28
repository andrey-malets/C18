#include <assert.h>
#include <stdlib.h>

#include "point.h"


struct point *init_point(void *memory, int x, int y) {
  struct point *p = memory;
  p->x = x;
  p->y = y;
  return p;
}

struct point *new_point(int x, int y) {
  void *memory = malloc(POINT_SIZE);
  assert(memory);
  return init_point(memory, x, y);
}

void free_point(struct point *p) {
  free(p);
}

double distance(const struct point *p1,
                const struct point *p2) {
  unsigned squared_distance =
      (p2->x - p1->x) * (p2->x - p1->x) +
      (p2->y - p1->y) * (p2->y - p1->y);
  double value = sqrt(squared_distance);
  return value;
}
