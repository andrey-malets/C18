int main(void) {
  int x = 10;
  x += x++ + ++x;
  // x += ++x + x++;
  return x;
}
