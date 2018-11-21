#include <inttypes.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>


struct factorial_state {
  jmp_buf buf;
  uint32_t n;
  uint64_t factorial;
  uint32_t _factorial_impl_rv;
};


void factorial_impl(struct factorial_state *state) {
  if (state->n == 0) {
    state->_factorial_impl_rv = state->factorial;
    longjmp(state->buf, 2);
  } else {
    state->factorial = state->factorial * state->n;
    state->n = state->n - 1;

    longjmp(state->buf, 1);
  }
}


uint64_t factorial(uint32_t n) {
  struct factorial_state state = {.n = n, .factorial = 1};

  if (setjmp(state.buf) < 2) {
    factorial_impl(&state);
  }

  return state._factorial_impl_rv;
}


int main(void) {
  printf("   %" PRIu64 "\n", factorial(10));
  printf("   %" PRIu64 "\n", factorial(5));
}
