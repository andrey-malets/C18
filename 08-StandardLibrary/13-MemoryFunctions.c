#include <stdio.h>
#include <string.h>

int main(void) {
  char data1[4] = {0, 1, 2, 0};
  char data2[4] = {0, 1, 2, 3};
  printf("%d\n", strcmp(data1, data2));
  printf("%d\n", memcmp(data1, data2,
                      sizeof(data1)));

  strcpy(data1, data2);
  printf("%d\n", strcmp(data1, data2));
  printf("%d\n", memcmp(data1, data2,
                      sizeof(data1)));

  memcpy(data1, data2, sizeof(data1));
  printf("%d\n", strcmp(data1, data2));
  printf("%d\n", memcmp(data1, data2,
                      sizeof(data1)));
}
