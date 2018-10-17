#include <stdio.h>
#include <stdarg.h>

enum Type {
    TypeNone,
    TypeInt,
    TypeDouble,
};

int calc_sum(int* types, ...) {
    int result = 0;

    va_list args;
    va_start(args, types);

    for (int* type = types; *type != TypeNone; type++) {
        if (*type == TypeInt) {
            result += va_arg(args, int);
        } else {
            result += va_arg(args, double);
        }
    }

    va_end(args);

    return result;
}

int main() {
    int types[] = {TypeInt, TypeDouble, TypeInt};
    printf("%d\n", calc_sum(types, 3, 4.5f, 5));
    printf("%d\n", calc_sum(types, 3.5f, 4.5f, 5));
    return 0;
}
