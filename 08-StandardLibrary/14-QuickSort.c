#include <stdio.h>
#include <stdlib.h>

typedef int (*comp)(const void*, const void*);

int int_less(const void *a, const void *b) {
  return *((int*)a) - *((int*)b);
}

int int_greater(const void *a, const void *b) {
  return int_less(b, a);
}

void print(const int numbers[], size_t size) {
  for (size_t i = 0; i != size; ++i)
    printf("%d%c", numbers[i], i == size - 1 ? '\n' : ' ');
}

int main(void) {
  int numbers[] = {3, 7, 6, 1, 18, 22};
  const size_t size = sizeof(numbers) / sizeof(numbers[0]);

  qsort(numbers, size, sizeof(numbers[0]), int_less);
  print(numbers, size);

  qsort(numbers, size, sizeof(numbers[0]), int_greater);
  print(numbers, size);
}
