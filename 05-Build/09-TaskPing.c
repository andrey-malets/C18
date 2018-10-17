#include "09-TaskPing.h"

#include "09-TaskPong.h"

#include <stdio.h>

void ping(int x) {
    if (x > 0) {
        printf("ping %d\n", x);
        pong(x - 1);
    }
}
