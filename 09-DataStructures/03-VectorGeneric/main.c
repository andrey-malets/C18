#include "vectors.h"

#include <assert.h>
#include <stdio.h>

void vector_int() {
  VECTOR_TYPE(int) *v = VECTOR_FUNC(empty, int)();

  assert(v = VECTOR_FUNC(resize, int)(v, 20, 0));

  for (size_t i = 0; i < VECTOR_FUNC(size, int)(v); ++i) {
    VECTOR_FUNC(set_elem, int)(v, i, i + 5);
  }

  assert(v = VECTOR_FUNC(push_back, int)(v, 99));

  for (int i = VECTOR_FUNC(size, int)(v) - 1; i >= 0; --i) {
    printf("%d, ", VECTOR_FUNC(get_elem, int)(v, i));
  }

  printf("\n");

  VECTOR_FUNC(free, int)(v);
}

void vector_struct() {
  VECTOR_TYPE(struct_A) *v = VECTOR_FUNC(empty, struct_A)();
  struct A default_val = {.x = 1, .y = 0.2};

  assert(v = VECTOR_FUNC(resize, struct_A)(v, 10, default_val));

  for (size_t i = 0; i < VECTOR_FUNC(size, struct_A)(v); ++i) {
    struct A new_val = {.x = i + 1, .y = (float)i * 2.5f};
    VECTOR_FUNC(set_elem, struct_A)(v, i, new_val);
  }

  for (int i = VECTOR_FUNC(size, struct_A)(v) - 1; i >= 0; --i) {
    struct A value = VECTOR_FUNC(get_elem, struct_A)(v, i);
    printf("%.2f -- %d\n", value.y, value.x);
  }

  VECTOR_FUNC(free, struct_A)(v);
}

int main(void) {
  vector_int();
  vector_struct();

  return 0;
}
