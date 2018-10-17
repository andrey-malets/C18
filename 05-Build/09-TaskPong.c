#include "09-TaskPong.h"

#include "09-TaskPing.h"

#include <stdio.h>

void pong(int x) {
    if (x > 0) {
        printf("pong %d\n", x);
        ping(x - 1);
    }
}
