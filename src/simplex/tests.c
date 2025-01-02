#include <stdio.h>
#include <stdlib.h>
#include "simplex.h"

void test_case_1()
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

  printf("Test Case 1:\n");
  for (int i = 0; i < 3; i++)
    printf("x[%d] = %f\n", i, solution->x[i]);
  printf("Optimal value: %f\n", solution->z);
  printf("Status: %d\n", solution->status);
}

void test_case_2()
{
  double c[2] = {2.0, -1.0};
  double b[2] = {2.0, -4.0};
  double arr[2][2] = {
      {2.0, -1.0},
      {1.0, -5.0}};

  double **A = (double **)malloc(2 * sizeof(double *));
  for (int i = 0; i < 2; i++)
  {
    A[i] = (double *)malloc(2 * sizeof(double));
    for (int j = 0; j < 2; j++)
    {
      A[i][j] = arr[i][j];
    }
  }

  StandardForm S = {2, 2, A, b, c};
  SimplexSolution *solution = simplex(&S);

  printf("Test Case 2:\n");
  for (int i = 0; i < 2; i++)
    printf("x[%d] = %f\n", i, solution->x[i]);
  printf("Optimal value: %f\n", solution->z);
  printf("Status: %d\n", solution->status);
}

void test_case_3()
{
  double c[2] = {18, 12.5};
  double b[3] = {20.0, 12.0, 16.0};
  double arr[3][2] = {
      {1.0, 1.0},
      {1.0, 0},
      {0, 1.0}};

  double **A = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++)
  {
    A[i] = (double *)malloc(2 * sizeof(double));
    for (int j = 0; j < 2; j++)
    {
      A[i][j] = arr[i][j];
    }
  }

  StandardForm S = {3, 2, A, b, c};
  SimplexSolution *solution = simplex(&S);

  printf("Test Case 3:\n");
  for (int i = 0; i < 3; i++)
    printf("x[%d] = %f\n", i, solution->x[i]);
  printf("Optimal value: %f\n", solution->z);
  printf("Status: %d\n", solution->status);
}

void test_case_4()
{
  double c[2] = {5.0, -3.0};
  double b[2] = {1.0, 2.0};
  double arr[2][2] = {
      {1.0, -1.0},
      {2.0, 1.0}};

  double **A = (double **)malloc(2 * sizeof(double *));
  for (int i = 0; i < 2; i++)
  {
    A[i] = (double *)malloc(2 * sizeof(double));
    for (int j = 0; j < 2; j++)
    {
      A[i][j] = arr[i][j];
    }
  }

  StandardForm S = {2, 2, A, b, c};
  SimplexSolution *solution = simplex(&S);

  printf("Test Case 4:\n");
  for (int i = 0; i < 2; i++)
    printf("x[%d] = %f\n", i, solution->x[i]);
  printf("Optimal value: %f\n", solution->z);
  printf("Status: %d\n", solution->status);
}

void test_case_5()
{
  double c[3] = {1, 1, 1};
  double b[2] = {10000, 30000};
  double arr[2][3] = {
      {2, 7.5, 3},
      {20, 5, 10}};

  double **A = (double **)malloc(2 * sizeof(double *));
  for (int i = 0; i < 2; i++)
  {
    A[i] = (double *)malloc(3 * sizeof(double));
    for (int j = 0; j < 3; j++)
    {
      A[i][j] = arr[i][j];
    }
  }

  StandardForm S = {2, 3, A, b, c};
  SimplexSolution *solution = simplex(&S);

  printf("Test Case 5:\n");
  for (int i = 0; i < 3; i++)
    printf("x[%d] = %f\n", i, solution->x[i]);
  printf("Optimal value: %f\n", solution->z);
  printf("Status: %d\n", solution->status);
}

void test_case_6()
{
  double c[2] = {1, 3};
  double b[3] = {8, -3, 2};
  double arr[3][2] = {
      {1, -1},
      {-1, -1},
      {-1, 4}};

  double **A = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++)
  {
    A[i] = (double *)malloc(2 * sizeof(double));
    for (int j = 0; j < 3; j++)
    {
      A[i][j] = arr[i][j];
    }
  }

  StandardForm S = {3, 2, A, b, c};
  SimplexSolution *solution = simplex(&S);

  printf("Test Case 6:\n");
  for (int i = 0; i < 2; i++)
    printf("x[%d] = %f\n", i, solution->x[i]);
  printf("Optimal value: %f\n", solution->z);
  printf("Status: %d\n", solution->status);
}

void test_case_7()
{
  double c[2] = {1, 2};
  double b[3] = {4, -12, 1};
  double arr[3][2] = {
      {1, 2},
      {-2, -6},
      {0, 1}};

  double **A = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++)
  {
    A[i] = (double *)malloc(2 * sizeof(double));
    for (int j = 0; j < 3; j++)
    {
      A[i][j] = arr[i][j];
    }
  }

  StandardForm S = {3, 2, A, b, c};
  SimplexSolution *solution = simplex(&S);

  printf("Test Case 7:\n");
  for (int i = 0; i < 2; i++)
    printf("x[%d] = %f\n", i, solution->x[i]);
  printf("Optimal value: %f\n", solution->z);
  printf("Status: %d\n", solution->status);
}

void test_case_8()
{
  double c[2] = {1, 3};
  double b[3] = {-1, -3, 2};
  double arr[3][2] = {
      {-1, 1},
      {-1, -1},
      {-1, 4}};

  double **A = (double **)malloc(3 * sizeof(double *));
  for (int i = 0; i < 3; i++)
  {
    A[i] = (double *)malloc(2 * sizeof(double));
    for (int j = 0; j < 3; j++)
    {
      A[i][j] = arr[i][j];
    }
  }

  StandardForm S = {3, 2, A, b, c};
  SimplexSolution *solution = simplex(&S);

  printf("Test Case 8:\n");
  for (int i = 0; i < 2; i++)
    printf("x[%d] = %f\n", i, solution->x[i]);
  printf("Optimal value: %f\n", solution->z);
  printf("Status: %d\n", solution->status);
}

void RunTests()
{
  test_case_1();
  test_case_2();
  test_case_3();
  test_case_4();
  test_case_5();
  test_case_6();
  test_case_7();
  test_case_8();
}