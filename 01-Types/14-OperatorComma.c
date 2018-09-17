int main(void) {
  int x = 10, y = (x = x++);
  return x++, (x = ++y), x;
}
