#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(condition, operation, filename) \
  do { \
    if (!(condition)) { \
      fprintf(stderr, "failed to %s %s: %s\n", \
              operation, filename, strerror(errno)); \
      exit(1); \
    } \
  } while (0)

int main(int ac, char *av[]) {
  FILE *fp;
  char buffer[1024];
  for (int i = 1; i != ac; ++i) {
    size_t read;
    CHECK(fp = fopen(av[i], "r"), "open", av[i]);
    CHECK(read = fread(buffer, sizeof(buffer[0]), sizeof(buffer), fp),
          "read from", av[i]);

    size_t to_write = read;
    while (to_write) {
      size_t written;
      CHECK(written = fwrite(buffer + read - to_write,
                             sizeof(buffer[0]), to_write, stdout),
            "write buffer to", "standard output");
      to_write -= written;
    }
    CHECK(fclose(fp) == 0, "close", av[i]);
  }
}
