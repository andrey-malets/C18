#include <stdio.h>
#include <string.h>

int main(void) {

  const char hello[] = "Hello, ";
  const char world[] = "world!";
  const char ya[10] = {'y', 'a'};

  char all[100];

  strcpy(all, hello);
  printf("%s\n", all);

  printf("%s\n",
         strcpy(strcpy(all, hello),
                world));

  all[0] = '\0';
  printf("%s\n",
         strcat(strcat(all, hello),
                world));
}
