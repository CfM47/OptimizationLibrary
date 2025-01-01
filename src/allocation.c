#include <stdlib.h>
#include <string.h>

int *int_allocate_array(size_t size)
{
  int *array = (int *)malloc(size * sizeof(int));
  if (array)
  {
    for (size_t i = 0; i < size; ++i)
    {
      array[i] = 0;
    }
  }
  return array;
}

double *double_allocate_array(size_t size)
{
  double *array = (double *)malloc(size * sizeof(double));
  if (array)
  {
    for (size_t i = 0; i < size; ++i)
    {
      array[i] = 0.0;
    }
  }
  return array;
}

int **int_allocate_matrix(size_t rows, size_t cols)
{
  int **matrix = (int **)malloc(rows * sizeof(int *));
  if (matrix)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      matrix[i] = (int *)malloc(cols * sizeof(int));
      if (matrix[i])
      {
        for (size_t j = 0; j < cols; ++j)
        {
          matrix[i][j] = 0;
        }
      }
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
      matrix[i] = (double *)malloc(cols * sizeof(double));
      if (matrix[i])
      {
        for (size_t j = 0; j < cols; ++j)
        {
          matrix[i][j] = 0.0;
        }
      }
    }
  }
  return matrix;
}
