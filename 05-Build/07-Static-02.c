#include <stdio.h>

int foo(int x);
int bar(int x);

int main() {
    printf("foo: %d\n", foo(10));
    printf("bar: %d\n", bar(10));
    return 0;
}
