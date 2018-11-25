#pragma once

#include <stddef.h>

union stack_header {
  size_t top;
  char placeholder[sizeof(max_align_t)];
};

void *stack_init(void *memory);

void stack_push(void *stack, const char *elem, size_t size);
int stack_pop(void *stack, char *elem, size_t size);

#define STACK_SIZE(type, nelem) \
  (sizeof(union stack_header) + sizeof(type) * nelem)

#define STACK_PUSH(stack, value) \
  stack_push(stack, (char *)&value, sizeof(value))

#define STACK_POP(stack, value) \
  stack_pop(stack, (char *)&value, sizeof(value))
