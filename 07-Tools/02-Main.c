#include <stdlib.h>
#include <stdio.h>

#include "02-SolveQuadraticEquation.h"

int main(int ac, char *av[]) {
  int a = atoi(av[1]);
  int b = atoi(av[2]);
  int c = atoi(av[3]);

  float x1, x2;
  int success = solve_qe(a, b, c, &x1, &x2);

  printf("%f %f\n", x1, x2);
  return (success == 1) ? 0 : 1;
}
