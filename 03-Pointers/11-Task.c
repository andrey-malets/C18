#include <stdio.h>
#include <stdlib.h>

int main(void) {
  const char message[] =
    "  VCS EKB Zapad   #1874 ";
  const char *words[10] = {NULL};
  size_t wi = 0;
  const char *begin = NULL;
  for (const char *c = message; *c; ++c) {
    if (*c == ' ') {
      if (begin) {
        begin = NULL;
      }
    } else {
      if (!begin) {
        words[wi++] = begin = c;
      }
    }
  }

  for (size_t i = 0;
       i != 10 && words[i]; ++i)
    printf("Word: %s\n", words[i]);
}
