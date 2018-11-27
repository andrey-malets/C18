#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "vector_impl.h"

#define VECTOR_FUNC(NAME, SUFFIX) NAME ## _vector ## SUFFIX

#define VECTOR_TYPE(SUFFIX) struct Vector ## SUFFIX

#define DECLARE_VECTOR_INTERFACE(ELEM_TYPE, SUFFIX) \
    VECTOR_TYPE(SUFFIX) { \
      struct vector_base base; \
      ELEM_TYPE data[]; \
    }; \
    VECTOR_TYPE(SUFFIX) *empty_vector ## SUFFIX(); \
    void free_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v); \
    VECTOR_TYPE(SUFFIX) *resize_vector ## SUFFIX( \
        VECTOR_TYPE(SUFFIX) *v, size_t new_size, \
        ELEM_TYPE default_val); \
    size_t size_vector ## SUFFIX(\
        const VECTOR_TYPE(SUFFIX) *v); \
    ELEM_TYPE get_elem_vector ## SUFFIX(\
        const VECTOR_TYPE(SUFFIX) *v, size_t index); \
    void set_elem_vector ## SUFFIX( \
        VECTOR_TYPE(SUFFIX) *v, size_t index, \
        ELEM_TYPE elem); \
    VECTOR_TYPE(SUFFIX) *push_back_vector ## SUFFIX( \
        VECTOR_TYPE(SUFFIX) *v, ELEM_TYPE elem);

#define DECLARE_VECTOR_IMPL(ELEM_TYPE, SUFFIX) \
    VECTOR_TYPE(SUFFIX) *empty_vector ## SUFFIX() { \
      static VECTOR_TYPE(SUFFIX) v; \
      v.base.size = 0; \
      v.base.capacity = 0; \
      return &v; \
    } \
    void free_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v) { \
      if (v->base.capacity) \
        free(v); \
    } \
    static VECTOR_TYPE(SUFFIX) *realloc_vector ## SUFFIX(VECTOR_TYPE(SUFFIX)* v, size_t new_size) { \
      return (VECTOR_TYPE(SUFFIX) *)realloc_vector_impl( \
          (struct vector_base *)v, \
          offsetof(VECTOR_TYPE(SUFFIX), data), \
          sizeof(ELEM_TYPE), new_size); \
    } \
    VECTOR_TYPE(SUFFIX) *resize_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v, size_t new_size, ELEM_TYPE default_val) { \
      VECTOR_TYPE(SUFFIX) *new_vector = new_size > v->base.capacity \
        ? (VECTOR_TYPE(SUFFIX) *) VECTOR_FUNC(realloc, SUFFIX)(v, new_size) \
        : v; \
      if (new_vector) { \
        for (size_t i = new_vector->base.size; i < new_size; ++i) \
          VECTOR_FUNC(set_elem, SUFFIX)(new_vector, i, default_val); \
        new_vector->base.size = new_size; \
      } \
      return new_vector; \
    } \
    size_t size_vector ## SUFFIX(const VECTOR_TYPE(SUFFIX) *v) { \
      return v->base.size; \
    } \
    ELEM_TYPE get_elem_vector ## SUFFIX(const VECTOR_TYPE(SUFFIX) *v, size_t index) { \
      return v->data[index]; \
    } \
    void set_elem_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v, size_t index, ELEM_TYPE elem) { \
      v->data[index] = elem; \
    } \
    VECTOR_TYPE(SUFFIX) *push_back_vector ## SUFFIX(VECTOR_TYPE(SUFFIX) *v, ELEM_TYPE elem) { \
      VECTOR_TYPE(SUFFIX) *new_vector = v->base.size == v->base.capacity \
        ? VECTOR_FUNC(realloc, SUFFIX)(v, v->base.size + 1) \
        : v; \
      if (new_vector) { \
        new_vector->data[new_vector->base.size] = elem; \
        ++new_vector->base.size; \
      } \
      return new_vector; \
    }
