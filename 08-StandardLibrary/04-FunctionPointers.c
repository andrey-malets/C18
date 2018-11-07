int twice(int value) { return value * 2; }
int inc(int value) { return ++value; }

typedef int (*int_f)(int);

int combine(int (*f2)(int), int_f f1,
            int value) {
  return f2((*f1)(value));
}

int main(void) {
  return combine(&twice, inc, 10);
}
