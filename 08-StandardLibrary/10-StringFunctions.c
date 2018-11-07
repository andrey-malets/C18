#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  const char hello[] = "Hello, ";
  const char world[] = {
    'w', 'o', 'r', 'l', 'd', '!',
  };
  const char ya[10] = {'y', 'a'};

  printf("%tu\n", strlen(hello));
  printf("%tu\n", strlen(world));
  printf("%tu\n", strlen(ya));
  puts("");
  printf("%d\n", isalpha(world[0]));
  printf("%d\n", isalpha(world[5]));
}
