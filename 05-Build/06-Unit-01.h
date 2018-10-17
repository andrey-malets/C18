#pragma once

int dup_body(int x);
inline int dup_inl(int x) {
    return 2 * x;
}
static int dup_st(int x) {
    return 2 * x;
}
extern int var;

int foo();
