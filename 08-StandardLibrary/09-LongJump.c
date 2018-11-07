#include <setjmp.h>
#include <stdio.h>

static jmp_buf jump_buffer;

void f1(int ac) {
  fputs("inside f1\n", stderr);
  if (ac != 1) {
    longjmp(jump_buffer, 1);
    fputs("after longjmp\n", stderr);
  }
}

void f2(int ac) {
  fputs("inside f2\n", stderr);
  f1(ac);
  fputs("after call f2 -> f1\n", stderr);
}

int main(int ac, char *av[]) {
  if (setjmp(jump_buffer) != 0) {
    fputs("return from longjmp\n", stderr);
  } else {
    f2(ac);
    fputs("normal return\n", stderr);
  }
}
