#include "01-DecompositionFunc.h"
#include "01-DecompositionLog.h"

int main(int ac, char *av[]) {
  message("Starting calculation");
  int sum = parse_and_sum(ac, av);
  message("Calculation end");
  return sum;
}
