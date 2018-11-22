#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERIFY(condition, operation, filename, rv, value, exit) \
  do { \
    if (!(condition)) { \
      fprintf(stderr, "failed to %s %s: %s\n", \
              operation, filename, strerror(errno)); \
      rv = value; \
      exit; \
    } \
  } while (0)


#define CHECK(condition, operation, filename, rv, value, label) \
  VERIFY(condition, operation, filename, rv, value, goto label)


#define ROLLBACK(condition, operation, filename, rv, value) \
  VERIFY(condition, operation, filename, rv, value, (void)0)


int main(int ac, char *av[]) {
  FILE *fp;
  char buffer[128];
  int rv = 0;
  for (int i = 1; i != ac; ++i) {
    size_t read;
    CHECK(fp = fopen(av[i], "r"), "open", av[i], rv, 1, exit);

    while (!feof(fp)) {
      read = fread(buffer, sizeof(buffer[0]), sizeof(buffer), fp);
      CHECK(!ferror(fp), "read from", av[i], rv, 2, cleanup);

      size_t to_write = read;
      CHECK(to_write == fwrite(buffer + read - to_write,
                               sizeof(buffer[0]), to_write, stdout),
            "write buffer to", "standard output", rv, 3, cleanup);
    }
    CHECK(fclose(fp) == 0, "close", av[i], rv, 4, exit);
    continue;

cleanup:
    ROLLBACK(fclose(fp) == 0, "close", av[i], rv, 5);
    break;
  }
exit:
  return rv;
}
