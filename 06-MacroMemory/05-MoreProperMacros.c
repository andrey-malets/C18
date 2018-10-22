#include <stdio.h>

enum LOG_LEVEL {
  ERROR, WARNING, INFO, DEBUG
};

#define LOG(level, msg) \
  if (level <= CURRENT_LOG_LEVEL) \
    fprintf(stderr, "%s: " msg "\n", #level)

#define PLOG(level, msg, ...) \
  if (level <= CURRENT_LOG_LEVEL) \
    fprintf(stderr, "%s: " msg "\n", #level, __VA_ARGS__)

#define CURRENT_LOG_LEVEL WARNING

int main(void) {
  LOG(INFO, "some shit happened");
  LOG(ERROR, "some bad shit happened!");

  int x = 10;
  PLOG(ERROR, "some bad shit happened: x == %d!", x);
}
