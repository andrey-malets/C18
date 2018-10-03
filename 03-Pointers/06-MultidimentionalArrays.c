#include <stdio.h>

int main(void) {
  int x[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int y[3][2] = {{1, 2}, {3, 4}, {5, 6}};

  printf("%d\n", x[0][0] == y[0][0]);
  printf("%d\n", x[0][1] == y[0][1]);
  // printf("%d\n", x[0][2] == y[0][2]);
  printf("%d\n",
         sizeof(x[0]) == sizeof(y[0]));
}
