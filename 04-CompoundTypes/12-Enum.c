#include <stdio.h>

enum color {
  RED = 1,
  GREEN,
  BLUE = 1 << 10,
};

void print_color(int color) {
  switch (color) {
  case RED:
    printf("RED\n"); break;
  case GREEN:
    printf("GREEN\n"); break;
  case BLUE:
    printf("BLUE\n"); break;
  }
}

int main(int ac, char* av[]) {
  print_color(ac);
}
