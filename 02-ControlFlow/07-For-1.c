#include <stdio.h>

int main(void) {
  int x, y;

  for (x = 0; x != 10; ++x) {
    for (y = 0; y != 10; ++y, ++x) {
      if (x + y == 7) {
        goto exit;
      }
    }
  }
exit:

  printf("%d %d\n", x, y);
}
