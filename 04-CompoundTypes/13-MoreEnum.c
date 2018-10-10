#include <inttypes.h>
#include <stdio.h>

enum regex_flags {
    IS_GLOBAL = 1 << 0,
    CASE_INSENSITIVE = 1 << 1,
    MULTILINE = 1 << 2,
    UNUSED_FIELD = 1 << 3,
    UNICODE = 1 << 4
};

// enum another_enum {
// // ...
//     UNUSED_FIELD
// // ...
// };

void match(
    // const char* pattern,
    // const char* str,
    // char* result,
    uint8_t flags)
{
    if (flags & IS_GLOBAL) printf("g");
    if (flags & CASE_INSENSITIVE) printf("i");
    if (flags & MULTILINE) printf("m");
    if (flags & UNICODE) printf("u");

    puts("");

    // ...
}

int main(void) {
    match(
        // pattern, str, result1,
        IS_GLOBAL | MULTILINE
    );
    match(
        // pattern, str, result1,
        CASE_INSENSITIVE | MULTILINE | IS_GLOBAL
    );
}
