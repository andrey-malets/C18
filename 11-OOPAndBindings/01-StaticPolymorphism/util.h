#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

#define FOREACH(i, x) \
  for (size_t i = 0; i != ARRAYSIZE(x); ++i)
