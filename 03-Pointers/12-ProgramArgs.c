#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
  printf("%d\n", argc);

  for (int i = 0; i != argc; ++i) {
    printf(" %s\n", argv[i]);
  }

  puts("");

  for (; *envp; envp++) {
    puts(*envp);
  }
}
