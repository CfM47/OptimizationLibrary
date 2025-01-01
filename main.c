#include <stdio.h>

#include "src/optimization.h"

int main()
{
  double c[3] = {3.0, 1.0, 2.0};
  double b[3] = {30.0, 24.0, 36.0};

  double arr[3][3] = {
      {1.0, 1.0, 3.0},
      {2.0, 2.0, 5.0},
      {4.0, 1.0, 2.0}};

  double **A = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++)
  {
    A[i] = (double *)malloc(3 * sizeof(double));
    for (int j = 0; j < 3; j++)
    {
      A[i][j] = arr[i][j];
    }
  }

  StandardForm S = {3, 3, A, b, c};
  SimplexSolution *solution = simplex(&S);

  printf("Optimal solution:\n");
  for (int i = 0; i < 3; i++)
    printf("x[%d] = %f\n", i, solution->x[i]);

  printf("Optimal value: %f\n", solution->z);

  return 0;
}