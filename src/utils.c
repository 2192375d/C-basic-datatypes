#include "utils.h"
#include <stdio.h>

int ds_max(int a, int b) {
    if (a >= b) {
        return a;
    }

    return b;
}

void ds_assert(char *message) {
    fprintf(stderr, "assert: %s\n", message);
}
