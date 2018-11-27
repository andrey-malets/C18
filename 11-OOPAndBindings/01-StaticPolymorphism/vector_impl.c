#include "vector_impl.h"

struct vector_base *realloc_vector_impl(
    struct vector_base *v, size_t data_offset,
    size_t elem_size, size_t new_size) {
  if (new_size == 0)
    return v;
  size_t new_capacity = v->capacity ? v->capacity : 1;
  while (new_capacity < new_size)
    new_capacity <<= 1;

  size_t old_size = v->size;
  size_t mem_size = data_offset + new_capacity * elem_size;
  struct vector_base *new_vector = v->capacity ?
      realloc(v, mem_size) : malloc(mem_size);

  if (new_vector) {
    new_vector->capacity = new_capacity;
    new_vector->size = old_size;
  }

  return new_vector;
}
