#include <stdio.h>

#include "src/optimization.h"

int main()
{

  // test 1
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
  printf("Status: %d\n", solution->status);

  // test 2
  double c2[2] = {2.0, -1.0};
  double b2[2] = {2.0, -4.0};

  double arr2[2][2] = {
      {2.0, -1.0},
      {1.0, -5.0}};

  double **A2 = (double **)malloc(2 * sizeof(double *));
  for (int i = 0; i < 2; i++)
  {
    A2[i] = (double *)malloc(2 * sizeof(double));
    for (int j = 0; j < 2; j++)
    {
      A2[i][j] = arr2[i][j];
    }
  }
  StandardForm S2 = {2, 2, A2, b2, c2};
  SimplexSolution *solution2 = simplex(&S2);

  printf("Optimal solution:\n");
  for (int i = 0; i < 2; i++)
    printf("x[%d] = %f\n", i, solution2->x[i]);

  printf("Optimal value: %f\n", solution2->z);
  printf("Status: %d\n", solution2->status);

  return 0;
}