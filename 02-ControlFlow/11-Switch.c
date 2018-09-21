int main(void) {
  char op1 = '*', op2 = ',';
  int priority;

  switch (op1) {
  case '+':
  case '-':
    priority = 0;

  case '^':
  case '|':
  case '&':
    priority = 0;

  case '*':
  case '/':
    priority = 1;

  case '=':
    priority = -1;
  }

  return priority;
}
