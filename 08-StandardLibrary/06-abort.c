#include <stdio.h>
#include <stdlib.h>

void cleanup(void) {
  puts("cleanup!");
}

int main(void) {
  puts("start");
  atexit(&cleanup);
  if (1 == 0) {
    fputs("something very bad happened!\n",
          stderr);
    abort();
    puts("apocalypse");
  }
}
