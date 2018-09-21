#include <stdio.h>

int main(void) {
  const char msg[] = "Hello, world!";
  const size_t size =
      sizeof(msg) / sizeof(msg[0]);

  printf("%lu\n", size);

  printf("%s\n", msg);
  for (size_t i = 0; i != size; ++i) {
    putchar(msg[i]);
  }
  putchar('\n');

  for (size_t i = 0; msg[i]; ++i) {
    putchar(msg[i]);
  }
  putchar('\n');
}
