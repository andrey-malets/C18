#include "01-DecompositionFunc.h"

int parse_and_sum(int ac, char *av[]) {
  int sum = 0;
  for (int i = 1; i != ac; ++i)
    sum += atoi(av[i]);

  return sum;
}
