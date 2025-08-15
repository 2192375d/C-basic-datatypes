#ifndef ARRAY_H
#define ARRAY_H

/*__________________basic stuffs______________________________*/
void array_print(int array[], int N);

int array_get_maximum_index(int array[], int N);

int array_get_minimum_index(int array[], int N);

void matrix_print(int **matrix, int N, int M);

/*__________________provide useful array______________________*/

void array_constant_valued_get(int array[], int value, int N);

/*__________________sorting algorithm stuffs__________________*/
void array_bubble_sort(int array[], int N);

void array_selection_sort(int array[], int N);

void array_insertion_sort(int array[], int N);

void array_quick_sort(int array[], int N);

void array_merge_sort(int array[], int N);

/*__________________others____________________________________*/
int **matrix_array_to_pointer(int N, int M, int matrix[N][M]);

#endif
