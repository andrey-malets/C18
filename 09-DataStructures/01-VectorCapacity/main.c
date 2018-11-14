#include <vector_capacity.h>
#include <stdio.h>

int main(void) {
  struct Vector v = empty_vector();
  resize_vector(&v, 20);

  for (size_t i = 0; i < size_vector(&v); ++i) {
    set_elem_vector(&v, i, i + 5);
  }

  push_back_vector(&v, 99);

  for (int i = size_vector(&v) - 1; i >= 0; --i) {
    printf("%d, ", get_elem_vector(&v, i));
  }

  printf("\n");

  free_vector(&v);
}
