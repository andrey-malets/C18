#include <stdlib.h>

int main(int argc, char** argv) {
    int* a = malloc(sizeof(*a));
    free(a);
    if (argc == 2) {
        free(a);
    }
}
