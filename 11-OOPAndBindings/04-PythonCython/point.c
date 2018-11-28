#include <assert.h>
#include <stdlib.h>

#include "point.h"

double c_distance(const struct point p1,
                  const struct point p2) {
  unsigned squared_distance =
      (p2.x - p1.x) * (p2.x - p1.x) +
      (p2.y - p1.y) * (p2.y - p1.y);
  double value = sqrt(squared_distance);
  return value;
}
