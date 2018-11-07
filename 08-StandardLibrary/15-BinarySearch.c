#include <stdio.h>
#include <stdlib.h>

typedef int (*comp)(const void*, const void*);

int int_less(const void *a, const void *b) {
  return *((int*)a) - *((int*)b);
}

int int_greater(const void *a, const void *b) {
  return int_less(b, a);
}

void find(const int numbers[], size_t size, int value, comp cmp) {
  void *match;
  if ((match = bsearch(&value, numbers, size,
                       sizeof(numbers[0]), cmp))) {
    printf("found %d at position %td\n", value, (const int*)match - numbers);
  } else {
    printf("%d not found\n", value);
  }
}

int main(void) {
  int numbers[] = {3, 7, 6, 1, 18, 22};
  const size_t size = sizeof(numbers) / sizeof(numbers[0]);

  qsort(numbers, size, sizeof(numbers[0]), int_less);

  find(numbers, size, 10, int_less);
  find(numbers, size, 6, int_less);
  find(numbers, size, 6, int_greater);
}
