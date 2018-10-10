#include <assert.h>
#include <stdio.h>


int main(void) {
    float floatNum = 0.f;
    scanf("%f", &floatNum);

    static_assert(sizeof(float) == 4,
                  "float type is not 4-bytes long");

    char* internal = (char*)(&floatNum);

    unsigned numBit = 0;
    int sign = 1;
    int exponent = 0;
    double mantissa = 1.0;

    for (int i = sizeof(float) - 1; i >= 0; --i) {
        for (int j = 7; j >= 0; --j) {
            unsigned bit = (internal[i] >> j) & 1;
            printf("%u", bit);

            if (numBit == 0 || numBit == 8) {
                printf(" | ");
            }

            if (numBit == 0) { // sign
                sign = bit ? -1 : 1;
            } else if (numBit <= 8) { // exponent
                exponent |= (bit << (8 - numBit));
            } else { // mantissa
                if (bit) {
                    mantissa += (1.0 / (double)(1 << (numBit - 8)));
                }
            }
            ++numBit;
        }
    }

    printf("\n%d * 2 ^ (%d - 127) * %lf", sign, exponent, mantissa);
    printf("\n");

    return 0;
}

