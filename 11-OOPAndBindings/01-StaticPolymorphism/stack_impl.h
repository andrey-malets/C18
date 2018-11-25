#pragma once

#include "stack.h"

struct stack {
  union stack_header header;
  char data[];
};

#define AS_STACK(memory) ((struct stack *)(memory))
