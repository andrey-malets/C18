
#include "stdio.h"

// void ping(int);
// void pong(int);

// void ping(int); // no error
// void pong(int); // no error

void ping(int x) {
    if (x > 0) {
        printf("ping\n");
        pong(x - 1);
    }
}
void pong(int x) {
    if (x > 0) {
        printf("pong\n");
        ping(x - 1);
    }
}

int main() {
    ping(5);
    return 0;
}
