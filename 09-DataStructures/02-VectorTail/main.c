#include "vector_tail.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
  struct Vector *v = empty_vector();

  assert(v = resize_vector(v, 20));

  for (size_t i = 0; i < size_vector(v); ++i) {
    set_elem_vector(v, i, i + 5);
  }

  assert(v = push_back_vector(v, 99));

  for (int i = size_vector(v) - 1; i >= 0; --i) {
    printf("%d, ", get_elem_vector(v, i));
  }

  printf("\n");

  free_vector(v);
}
