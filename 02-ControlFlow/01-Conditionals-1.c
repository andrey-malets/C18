int main(void) {
  int x = 0;
  int y = (x != 0);

  if (y) {
    return 0;
  } else if (x != y) {
    return 1;
  } else {
    return 2;
  }
}
