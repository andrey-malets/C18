#include <stdio.h>

#define FOR_EACH_COLOR(expr) \
    expr(RED) expr(GREEN) expr(BLUE)

#define value(color) color,
    enum Color { FOR_EACH_COLOR(value) };
#undef value

void print_color(int color) {
  switch (color) {
#define print(color) \
  case color: printf(#color "\n"); break;
    FOR_EACH_COLOR(print)
#undef print
  }
}

int main(void) {
  print_color(RED);
  print_color(GREEN);
}
