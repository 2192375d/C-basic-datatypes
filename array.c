#ifndef ARRAY_H
#define ARRAY_H

#include "array.h"
#include "stdio.h"
#include "stdlib.h"

/*____________________________________________________________*/

void swap(int *x, int *y) {
    /*
     * The function swaps the two input parameters using pointers
     */

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/*____________________________________________________________*/

/*------------------------------------------------------------*/
//                                                            //
//                  basic stuffs                              //
//                                                            //
/*------------------------------------------------------------*/

////////////////////////////////////////////////////////////////

void array_print(int array[], int N) {
    /*
     * The function takes an input array, and prints it. Numbers are
     * seperated by a space.
     *
     * For example:
     *      array[5] = {1, 2, 3, 4, 5};
     *      The ouput will be "1 2 3 4 5"
     */

    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
}

////////////////////////////////////////////////////////////////

int array_get_maximum_index(int array[], int N) {
    /*
     * Takes an input array and returns index with maximum value
     * If array is empty, return -1
     */

    if (N == 0) {
        return -1;
    }

    int maximum_index = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] > array[maximum_index]) {
            maximum_index = i;
        }
    }

    return maximum_index;
}

////////////////////////////////////////////////////////////////

int array_get_minimum_index(int array[], int N) {
    /*
     * Takes an input array and returns index with minimum value
     * If array is empty, return -1
     */

    if (N == 0) {
        return -1;
    }

    int minimum_index = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] < array[minimum_index]) {
            minimum_index = i;
        }
    }

    return minimum_index;
}

////////////////////////////////////////////////////////////////

void matrix_print(int **matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

////////////////////////////////////////////////////////////////

/*------------------------------------------------------------*/
//                                                            //
//                  provide useful array                      //
//                                                            //
/*------------------------------------------------------------*/

void array_constant_valued_get(int array[], int value, int N) {

    for (int i = 0; i < N; i++) {
        array[i] = value;
    }
}

/*------------------------------------------------------------*/
//                                                            //
//                  sorting algorithms                        //
//                                                            //
/*------------------------------------------------------------*/

////////////////////////////////////////////////////////////////

void array_bubble_sort(int array[], int N) {

    _Bool swapped = 1;
    for (int i = 0; i < N - 1 && swapped == 1; i++) {
        swapped = 0;
        for (int j = 0; j < N - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
    }
}

////////////////////////////////////////////////////////////////

void array_selection_sort(int array[], int N) {

    int minimum_index = 0;

    for (int i = 0; i < N; i++) {
        minimum_index = array_get_minimum_index(array + i, N - i) + i;
        swap(array + i, array + minimum_index);
    }
}

////////////////////////////////////////////////////////////////

void array_insertion_sort(int array[], int N) {

    int temp = 0;
    int index = 0;

    for (int i = 1; i < N; i++) {

        temp = array[i];
        index = i - 1;

        while (index >= 0 && temp < array[index]) {
            array[index + 1] = array[index];
            index--;
        }

        array[index + 1] = temp;
    }
}

////////////////////////////////////////////////////////////////

void array_quick_sort(int array[], int N) {

    if (N <= 1) {
        return;
    }

    int pivot_value = array[N / 2];
    int array_left[N - 1];
    int array_right[N - 1];
    int count_left = 0;
    int count_right = 0;

    for (int i = 0; i < N; i++) {
        if (i == N / 2) {
            continue;
        }

        if (array[i] <= pivot_value) {
            array_left[count_left] = array[i];
            count_left++;
        } else {
            array_right[count_right] = array[i];
            count_right++;
        }
    }

    array_quick_sort(array_left, count_left);
    array_quick_sort(array_right, count_right);

    for (int i = 0; i < count_left; i++) {
        array[i] = array_left[i];
    }
    array[count_left] = pivot_value;
    for (int i = 0; i < count_right; i++) {
        array[i + count_left + 1] = array_right[i];
    }
}

////////////////////////////////////////////////////////////////

void array_merge_sort(int array[], int N) {

    // base case
    if (N == 1) {
        return;
    }

    // check if odd
    int odd = 0;
    if (N % 2 == 1) {
        odd = 1;
    }

    // create left and right subarrays
    int array_left[N / 2 + odd];
    int array_right[N / 2];

    for (int i = 0; i < N / 2; i++) {
        array_left[i] = array[i];
        array_right[i] = array[i + N / 2 + odd];
    }

    if (odd == 1) {
        array_left[N / 2] = array[N / 2];
    }

    // merge
    array_merge_sort(array_left, N / 2 + odd);
    array_merge_sort(array_right, N / 2);

    int i = 0;
    int j = 0;
    while (i < N / 2 + odd && j < N / 2) {
        if (array_left[i] <= array_right[j]) {
            array[i + j] = array_left[i];
            i++;
        } else {
            array[i + j] = array_right[j];
            j++;
        }
    }

    while (i < N / 2 + odd) {
        array[i + j] = array_left[i];
        i++;
    }
    while (j < N / 2) {
        array[i + j] = array_right[j];
        j++;
    }
}

////////////////////////////////////////////////////////////////

/*------------------------------------------------------------*/
//                                                            //
//                  others                                    //
//                                                            //
/*------------------------------------------------------------*/

////////////////////////////////////////////////////////////////

int **matrix_array_to_pointer(int N, int M, int matrix[N][M]) {
    /*
     * Takes an N by M input matrix, and dynamics allocate the matrix, and
     * return it
     *
     * complexity N * M
     */

    int **result_matrix = (int **)calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++) {
        result_matrix[i] = (int *)calloc(M, sizeof(int));
        for (int j = 0; j < M; j++) {
            result_matrix[i][j] = matrix[i][j];
        }
    }

    return result_matrix;
}

#endif
