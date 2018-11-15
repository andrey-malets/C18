#pragma once

#include <stdbool.h>
#include <stdlib.h>

#define VECTOR_FUNC(NAME, SUFFIX) NAME ## _vector ## SUFFIX

#define VECTOR_TYPE(SUFFIX) struct Vector ## SUFFIX

#define DECLARE_VECTOR_INTERFACE(ELEM_TYPE, SUFFIX) \
    VECTOR_TYPE(SUFFIX) { \
      size_t size; \
      size_t capacity; \
      ELEM_TYPE data[]; \
    }; \
    VECTOR_TYPE(SUFFIX) *empty_vector ## SUFFIX(); \
    void free_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v); \
    VECTOR_TYPE(SUFFIX) *resize_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v, size_t new_size, ELEM_TYPE default_val); \
    size_t size_vector ## SUFFIX(const VECTOR_TYPE(SUFFIX) *v); \
    ELEM_TYPE get_elem_vector ## SUFFIX(const VECTOR_TYPE(SUFFIX) *v, size_t index); \
    void set_elem_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v, size_t index, ELEM_TYPE elem); \
    VECTOR_TYPE(SUFFIX) *push_back_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v, ELEM_TYPE elem);

#define DECLARE_VECTOR_IMPL(ELEM_TYPE, SUFFIX) \
    VECTOR_TYPE(SUFFIX) *empty_vector ## SUFFIX() { \
      static VECTOR_TYPE(SUFFIX) v; \
      v.size = 0; \
      v.capacity = 0; \
      return &v; \
    } \
    void free_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v) { \
      if (v->capacity) \
        free(v); \
    } \
    static VECTOR_TYPE(SUFFIX) *realloc_vector ## SUFFIX(VECTOR_TYPE(SUFFIX)* v, size_t new_size) { \
      if (new_size == 0) \
        return v; \
      size_t new_capacity = v->capacity ? v->capacity : 1; \
      while (new_capacity < new_size) \
        new_capacity <<= 1; \
      size_t old_size = v->size; \
      size_t mem_size =  sizeof(VECTOR_TYPE(SUFFIX)) + new_capacity * sizeof(ELEM_TYPE); \
      VECTOR_TYPE(SUFFIX) *new_vector = v->capacity \
        ? (VECTOR_TYPE(SUFFIX) *) realloc(v, mem_size) \
        : (VECTOR_TYPE(SUFFIX) *) malloc(mem_size); \
      if (new_vector) { \
        new_vector->capacity = new_capacity; \
        new_vector->size = old_size; \
      } \
      return new_vector; \
    } \
    VECTOR_TYPE(SUFFIX) *resize_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v, size_t new_size, ELEM_TYPE default_val) { \
      VECTOR_TYPE(SUFFIX) *new_vector = new_size > v->capacity \
        ? (VECTOR_TYPE(SUFFIX) *) VECTOR_FUNC(realloc, SUFFIX)(v, new_size) \
        : v; \
      if (new_vector) { \
        for (size_t i = new_vector->size; i < new_size; ++i) \
          VECTOR_FUNC(set_elem, SUFFIX)(new_vector, i, default_val); \
        new_vector->size = new_size; \
      } \
      return new_vector; \
    } \
    size_t size_vector ## SUFFIX(const VECTOR_TYPE(SUFFIX) *v) { \
      return v->size; \
    } \
    ELEM_TYPE get_elem_vector ## SUFFIX(const VECTOR_TYPE(SUFFIX) *v, size_t index) { \
      return v->data[index]; \
    } \
    void set_elem_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v, size_t index, ELEM_TYPE elem) { \
      v->data[index] = elem; \
    } \
    VECTOR_TYPE(SUFFIX) *push_back_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v, ELEM_TYPE elem) { \
      VECTOR_TYPE(SUFFIX) *new_vector = v->size == v->capacity \
        ? VECTOR_FUNC(realloc, SUFFIX)(v, v->size + 1) \
        : v; \
      if (new_vector) { \
        new_vector->data[new_vector->size] = elem; \
        ++new_vector->size; \
      } \
      return new_vector; \
    }
