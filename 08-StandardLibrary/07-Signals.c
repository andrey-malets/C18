#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

void handler(int signum) {
#define HANDLE(sig) \
  case sig: \
    fprintf(stderr, #sig " caught!\n"); \
    break

  switch (signum) {
    HANDLE(SIGTERM);
    HANDLE(SIGINT);
  }
#undef HANDLE
}

int main(void) {
  signal(SIGTERM, handler);
  signal(SIGINT, handler);
  signal(SIGKILL, handler);
  pause();
  fprintf(stderr, "after pause");
}
