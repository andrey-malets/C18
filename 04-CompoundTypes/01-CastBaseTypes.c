#include "stdint.h"
#include "stdio.h"

int main() {
    int a = 4;
    uint64_t b = 4, c = (1UL << 31) + 10,
                    d = (1UL << 32) + 10;
    int f = -1;
    uint32_t g = -1;

    double e = 2.718281828;

    printf("%ld %u %lu\n",
           (long)a, (unsigned)a,
           (unsigned long)a);

    printf("%llu %llu %llu !!MAGIC!! %u %u %u\n",
           b, c, d,
           (uint32_t)b, (uint32_t)c, (uint32_t)d);

    printf("%d %u %llu\n", f, (uint32_t)f, (uint64_t)f);

    printf("%u %d\n", g, (int32_t)g);

    printf("%.2lf %d\n", e, (int32_t)e);
    printf("%llu %.7lf\n", b, (double)b);
}
