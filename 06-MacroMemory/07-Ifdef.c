#include <stdio.h>

#if defined(__GNUC__)
#  define ALIGNOF(type) __alignof__(type)
#elif defined(_MSC_VER)
#  define ALIGNOF(type) __alignof(type)
#else
#  error("unknown alignof")
#endif


int main(void) {
  printf("%lu\n", ALIGNOF(int));
  printf("%lu\n", ALIGNOF(long));
  printf("%lu\n", ALIGNOF(long long));
}
