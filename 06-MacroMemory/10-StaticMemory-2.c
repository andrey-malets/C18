#include <stdio.h>

#define SIZE 100500

char message[SIZE];

int main(void) {
  char message2[] = "Hello, world!";
  char message3[SIZE];

  printf("%p %p %p\n",
         (void *)message,
         (void *)message2,
         (void *)message3);

  return 0;
}
