#pragma once

#include "vector_generic.h"

struct A {
  int x;
  float y;
};

DECLARE_VECTOR_INTERFACE(int, int)
DECLARE_VECTOR_INTERFACE(char, char)
DECLARE_VECTOR_INTERFACE(struct A, struct_A)
