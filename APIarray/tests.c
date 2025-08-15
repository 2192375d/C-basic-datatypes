#include "array.h"
#include <stdio.h>
// #include <stdlib.h>

#define N 10

int main() {
    int arr[N] = {0, -3, 4, 2, 3, 9, 1, 7, 4, 6};

    array_print(arr, N);
    printf("\n");

    array_quick_sort(arr, N);

    array_print(arr, N);
    printf("\n");

    return 0;
}
