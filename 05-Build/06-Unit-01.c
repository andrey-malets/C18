#include "06-Unit-01.h"

int dup_body(int x) {
    return 2 * x;
}
extern inline int dup_inl(int x);
int var = 0;

int foo() {
    return dup_st(3);
}
