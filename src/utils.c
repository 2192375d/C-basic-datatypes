#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int ds_max(int a, int b) {
    if (a >= b) {
        return a;
    }

    return b;
}

void ds_assert(bool condition, char *source, char *message) {
    if (condition) {
        fprintf(stderr, "assert: %s - %s\n", source, message);
        exit(1);
    }
}
