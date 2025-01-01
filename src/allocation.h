#ifndef ALLOCATION_H
#define ALLOCATION_H

#include <stdlib.h>

int *int_allocate_array(size_t size);
double *double_allocate_array(size_t size);
int **int_allocate_matrix(size_t rows, size_t cols);
double **double_allocate_matrix(size_t rows, size_t cols);
void int_free_matrix(int **matrix, size_t rows);
void double_free_matrix(double **matrix, size_t rows);
void int_copy_array(int *dest, const int *src, size_t size);
void double_copy_array(double *dest, const double *src, size_t size);
void int_copy_matrix(int **dest, int **src, size_t rows, size_t cols);
void double_copy_matrix(double **dest, double **src, size_t rows, size_t cols);

#endif // ALLOCATION_H