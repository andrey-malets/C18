#include <stdio.h>
#include <stdlib.h>

void cleanup(void) {
  puts("cleanup!");
}

int main(void) {
  puts("start");
  atexit(&cleanup);
  puts("working...");
  exit(0);
  puts("after exit.");
}
