int X[100 * 1024 * 1024];

int main(void) {
  return X[sizeof(X) / sizeof(X[0]) - 1];
}
