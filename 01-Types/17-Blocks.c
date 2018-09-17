int main(void) {
  int x = 10, y, z;
  {
    int x = 20;
    int a = 30;
    y = x;
  }
  z = x;
  // z = a;
  return x + y + z;
}
