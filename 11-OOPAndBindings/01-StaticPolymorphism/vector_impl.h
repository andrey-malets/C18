#pragma once

#include <stdlib.h>

struct vector_base {
    size_t size;
    size_t capacity;
};

struct vector_base *realloc_vector_impl(
    struct vector_base *v, size_t data_offset,
    size_t elem_size, size_t new_size);
