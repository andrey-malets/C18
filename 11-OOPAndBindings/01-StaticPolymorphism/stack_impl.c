#include <string.h>

#include "stack_impl.h"

void *stack_init(void *memory) {
  struct stack *s = AS_STACK(memory);
  s->header.top = 0llu;
  return s;
}

void stack_push(void *stack, const char *elem, size_t size) {
  struct stack *s = AS_STACK(stack);
  memcpy(&s->data[s->header.top], elem, size);
  s->header.top += size;
}

int stack_pop(void *stack, char *elem, size_t size) {
  struct stack *s = AS_STACK(stack);
  if (!s->header.top) {
    return 0;
  } else {
    s->header.top -= size;
    memcpy(elem, &s->data[s->header.top], size);
    return 1;
  }
}
