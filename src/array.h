// array.h

/*
 * This file takes part of Lumiere's array library
 * The current file contains the API documentation of all functions from the
 * array library
 *
 * Note that the arrays here only works with integer
 */

#ifndef ARRAY_H
#define ARRAY_H

/*__________________basic stuffs______________________________*/

// prints the input array
void array_print(int array[], int N);

// returns the index of from the input array with the largest value
int array_get_maximum_index(int array[], int N);

// returns the index of from the input array with the smallest value
int array_get_minimum_index(int array[], int N);

// print the matrix of N rows M columns, note that the matrix will look
// misaligned due to negative values or value x S.T. |x| >= 10
void matrix_print(int **matrix, int N, int M);

/*__________________provide useful array______________________*/

// make all entries in the input array to hold 'value'
void array_constant_valued_get(int array[], int value, int N);

/*__________________sorting algorithm stuffs__________________*/

// the follow functions all do the job of sorting an array, for the specific
// time complexity, check the .c file

void array_bubble_sort(int array[], int N);

void array_selection_sort(int array[], int N);

void array_insertion_sort(int array[], int N);

void array_quick_sort(int array[], int N);

void array_merge_sort(int array[], int N);

/*__________________others____________________________________*/
// returns a pointer pointing to integer pointers, where each integer pointers
// has a size M and points to matrix[i][0], 0 <= i <= N
int **matrix_array_to_pointer(int N, int M, int matrix[N][M]);

#endif
