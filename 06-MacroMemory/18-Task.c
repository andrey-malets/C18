#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

int main(void) {
  const int X[2][3] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
  };

  const int Y[3][4] = {
    { 5, 6, 7, 8 },
    { 6, 7, 8, 9 },
    { 7, 8, 9, 0 },
  };

  int Z[ARRAY_SIZE(X)][ARRAY_SIZE(Y[0])];

  for (size_t i = 0; i != ARRAY_SIZE(X); ++i) {
    for (size_t j = 0; j != ARRAY_SIZE(Y[0]); ++j) {
      Z[i][j] = 0;
      for (size_t k = 0; k != ARRAY_SIZE(X[0]); ++k) {
        Z[i][j] += X[i][k] * Y[k][j];
      }
    }
  }

  for (size_t i = 0; i != ARRAY_SIZE(Z); ++i) {
    for (size_t j = 0; j != ARRAY_SIZE(Z[0]); ++j)
      printf("%4d%c", Z[i][j], j == ARRAY_SIZE(Z[0]) - 1 ? '\n' : ' ');
  }
}
