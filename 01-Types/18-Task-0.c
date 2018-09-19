int main(void) {
  int x = 29029, y = 101101;
  int gcd = 1001, lcm = 29 * 101 * 1001;
  return x * y == gcd * lcm && x * y / gcd == lcm;
}
