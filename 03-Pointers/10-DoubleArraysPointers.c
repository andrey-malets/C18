#include <stdio.h>

int main(void) {
  int x[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int y[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  int *p[2] = {&y[0][0], &x[1][0]};
  int **pp = p;
  printf("%d\n", **pp);
  printf("%d\n", pp[0][2]);
  printf("%d\n", pp[1][1]);
}
