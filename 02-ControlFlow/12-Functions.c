int priority(char op) {
  switch (op) {
  case '+': case '-':
    return 0;

  case '^': case '|': case '&':
    return 0;

  case '*': case '/':
    return 1;

  case '=':
    return -1;
  default:
    return -42;
  }
}

int main(void) {
  return priority('*') > priority('-');
}
