#include <math.h>
#include <stddef.h>

struct point {
  int x;
  int y;
};

const size_t POINT_SIZE = sizeof(struct point);

struct point *init_point(void *memory, int x, int y);

struct point *new_point(int x, int y);
void free_point(struct point *);

double distance(const struct point *p1,
                const struct point *p2);
