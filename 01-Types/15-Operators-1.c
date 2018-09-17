int main(void) {
  unsigned x = 2, y = 1;
  unsigned z = (x + y) * y;

  return x & (z + (y << 1));
}
