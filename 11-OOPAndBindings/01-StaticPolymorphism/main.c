#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "util.h"

struct point {
  int x; int y;
};

int main(void) {
  const int ints[] = {1, 2, 3, 4, 5};
  const struct point points[] = {
    {0, 3}, {4, 0}, {0, 0},
  };

  char istack_memory[STACK_SIZE(int, ARRAYSIZE(ints))];

  void *istack = stack_init(istack_memory);
  FOREACH(i, ints)
    STACK_PUSH(istack, ints[i]);

  FOREACH(i, ints) {
    int value;
    STACK_POP(istack, value);
    printf("%d%c", value, i == ARRAYSIZE(ints) -1 ? '\n' : ' ');
  }

  char *pstack_memory = malloc(
    STACK_SIZE(struct point, ARRAYSIZE(points)));
  void *pstack = stack_init(pstack_memory);

  FOREACH(p, points)
    STACK_PUSH(pstack, points[p]);

  FOREACH(p, points) {
    struct point value;
    STACK_POP(pstack, value);
    printf("(%d,%d)%c", value.x, value.y,
           p == ARRAYSIZE(points) -1 ? '\n' : ' ');
  }

  free(pstack_memory);
}
