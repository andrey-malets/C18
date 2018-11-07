#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[], char *envp[]) {
  for (size_t i = 0; *envp && i != 3; ++i) {
    printf("%s\n", *envp++);
  }

  puts("");
  printf("SHELL=%s\n", getenv("SHELL"));
  printf("USER=%s\n", getenv("USER"));
}
