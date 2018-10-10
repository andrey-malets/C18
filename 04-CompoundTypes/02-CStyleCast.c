int main(void) {
  int i = 0;
  // const char s[] = "Hello, world!";
  const int *p = &i;
  int *q = (int *)p;
  *q = 10;

  // char *s2 = (char *)s;
  // *s2 = 10;
}
