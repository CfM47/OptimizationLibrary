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
