#include <stdlib.h>
#include <string.h>

int *int_allocate_array(size_t size)
{
  int *array = (int *)calloc(size, sizeof(int));
  return array;
}

double *double_allocate_array(size_t size)
{
  double *array = (double *)calloc(size, sizeof(double));
  return array;
}

int **int_allocate_matrix(size_t rows, size_t cols)
{
  int **matrix = (int **)malloc(rows * sizeof(int *));
  if (matrix)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      matrix[i] = (int *)calloc(cols, sizeof(int));
    }
  }
  return matrix;
}

double **double_allocate_matrix(size_t rows, size_t cols)
{
  double **matrix = (double **)malloc(rows * sizeof(double *));
  if (matrix)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      matrix[i] = (double *)calloc(cols, sizeof(double));
    }
  }
  return matrix;
}

void int_free_matrix(int **matrix, size_t rows)
{
  if (matrix)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      free(matrix[i]);
    }
    free(matrix);
  }
}

void double_free_matrix(double **matrix, size_t rows)
{
  if (matrix)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      free(matrix[i]);
    }
    free(matrix);
  }
}

void int_copy_array(int *dest, const int *src, size_t size)
{
  memcpy(dest, src, size * sizeof(int));
}

void double_copy_array(double *dest, const double *src, size_t size)
{
  memcpy(dest, src, size * sizeof(double));
}

void int_copy_matrix(int **dest, int **src, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    memcpy(dest[i], src[i], cols * sizeof(int));
  }
}

void double_copy_matrix(double **dest, double **src, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    memcpy(dest[i], src[i], cols * sizeof(double));
  }
}