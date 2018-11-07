#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[]) {
  long n1 = atol(av[1]);
  long n2 = strtol(av[1], NULL, 10);

  char *end;
  long n3 = strtol(av[1], &end, 10);

  printf("%ld %ld %ld\n", n1, n2, n3);
  printf("%d\n", end == av[1]);
  printf("%d\n", *end == '\0');
}
