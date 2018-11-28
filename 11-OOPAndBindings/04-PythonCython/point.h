#include <math.h>
#include <stddef.h>

struct point {
  int x;
  int y;
};

double c_distance(const struct point p1,
                  const struct point p2);
