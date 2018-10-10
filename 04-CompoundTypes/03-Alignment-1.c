#include <stdio.h>
#include <stdlib.h>
#include <emmintrin.h>

__m128i* getAddr(size_t offset) {
    static char data[] =
        "Man, I suck at this game. Can't you give"
        "me a few pointers?";
    return (__m128i*)(data + offset);
}

int main(int argCount, char** argValue) {
    if (argCount >= 2) {
        size_t offsets[ 2 ] = {atol( argValue[ 1 ]),
                               atol( argValue[ 2 ])};
        printf(
            "%lld \n",
            _mm_add_epi16(
                *getAddr(offsets[0]),
                *getAddr(offsets[1])
            )[0]
        );
    }
}
