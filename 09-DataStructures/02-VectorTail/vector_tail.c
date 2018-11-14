#include "vector_tail.h"

struct Vector *empty_vector() {
  static struct Vector v;
  v.size = 0;
  v.capacity = 0;
  return &v;
}

void free_vector(struct Vector *v) {
  if (v->capacity)
    free(v);
}

static struct Vector *realloc_vector(struct Vector* v, size_t new_size) {
  if (new_size == 0)
    return v;

  size_t new_capacity = v->capacity ? v->capacity : 1;

  while (new_capacity < new_size)
    new_capacity <<= 1;

  size_t old_size = v->size;

  size_t mem_size =  sizeof(struct Vector) + new_capacity * sizeof(int);
  struct Vector *new_vector = v->capacity
    ? (struct Vector *) realloc(v, mem_size)
    : (struct Vector *) malloc(mem_size);

  if (new_vector) {
    new_vector->capacity = new_capacity;
    new_vector->size = old_size;
  }

  return new_vector;
}

struct Vector *resize_vector(struct Vector *v, size_t new_size) {
  struct Vector *new_vector = new_size > v->capacity
    ? (struct Vector *) realloc_vector(v, new_size)
    : v;

  if (new_vector) {
    for (size_t i = new_vector->size; i < new_size; ++i)
      set_elem_vector(new_vector, i, 0);

    new_vector->size = new_size;
  }

  return new_vector;
}

size_t size_vector(const struct Vector *v) {
  return v->size;
}

int get_elem_vector(const struct Vector *v, size_t index) {
  return v->data[index];
}

void set_elem_vector(struct Vector *v, size_t index, int elem) {
  v->data[index] = elem;
}

struct Vector *push_back_vector(struct Vector *v, int elem) {
  struct Vector *new_vector = v->size == v->capacity
    ? realloc_vector(v, v->size + 1)
    : v;

  if (new_vector) {
    new_vector->data[new_vector->size] = elem;
    ++new_vector->size;
  }

  return new_vector;
}
