#include <stdio.h>

#include "src/optimization.h"

int main()
{
  double arr[3][3] = {{1, 2, 0}, {3, 4, 4}, {5, 6, 3}};
  double vector[3] = {3, 7, 8};

  double **A = double_allocate_matrix(3, 3);
  double *b = (double *)malloc(3 * sizeof(double));

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      A[i][j] = arr[i][j];
    }
    b[i] = vector[i];
  }

  double *x = solve_system(A, b, 3);
  for (int i = 0; i < 3; i++)
  {
    printf("%f\n", x[i]);
  }
  return 0;
}