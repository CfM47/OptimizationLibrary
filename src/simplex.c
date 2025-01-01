#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

#include "allocation.h"

typedef struct
{
  int m, n;
  double **A;
  double *b;
  double *c;
} StandardForm;

typedef enum
{
  OPTIMAL,
  UNBOUNDED,
  INFEASIBLE
} SimplexStatus;

typedef struct
{
  double *x;
  double z;
  SimplexStatus status;
} SimplexSolution;

void pivot(double **T, double *B, int m, int n, int l, int e)
{
  int cols = n + m + 1;
  int rows = m + 1;
  double a_le = T[l][e];
  for (int i = 0; i < cols; i++)
    T[l][i] /= a_le;
  for (int i = 0; i < rows; i++)
  {
    if (i == l)
      continue;
    double a_ie = T[i][e];
    for (int j = 0; j < cols; j++)
      T[i][j] -= T[l][j] * a_ie;
  }
  B[l] = e;
}

double **build_table(StandardForm *S)
{
  int m = S->m;
  int n = S->n;
  int rows = m + 1;
  int cols = n + m + 1;
  double **T = double_allocate_matrix(rows, cols);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      T[i][j] = S->A[i][j];
    T[i][n + i] = 1;
    T[i][n + m] = S->b[i];
  }
  for (int j = 0; j < n; j++)
    T[m][j] = -S->c[j];
  return T;
}

int find_pivotColumn(double **T, int m, int n)
{
  int e = -1;
  int min = 0.0;
  for (int j = 0; j < n + m; j++)
  {
    if (T[m][j] < min)
    {
      min = T[m][j];
      e = j;
    }
  }
  return e;
}

int find_pivotRow(double **T, int m, int n, int e)
{
  int l = -1;
  double minRatio = DBL_MAX;
  for (int i = 0; i < m; i++)
  {
    if (T[i][e] <= 0)
      continue;
    double b_i = T[i][n + m];
    double a_il = T[i][e];
    if (minRatio > b_i / a_il)
    {
      minRatio = b_i / a_il;
      l = i;
    }
  }
  return l;
}

SimplexSolution *simplex(StandardForm *S)
{
  double *x = double_allocate_array(S->n);
  SimplexSolution *solution = malloc(sizeof(SimplexSolution));
  solution->x = x;

  double **T = build_table(S);
  double *B = double_allocate_array(S->m);
  for (int i = 0; i < S->m; i++)
    B[i] = S->n + i;

  int e;

  while ((e = find_pivotColumn(T, S->m, S->n)) >= 0)
  {
    int l = find_pivotRow(T, S->m, S->n, e);
    if (l == -1)
    {
      for (int i = 0; i < S->n; i++)
        solution->x[i] = INFINITY;

      solution->status = UNBOUNDED;
      solution->z = INFINITY;
    }
    pivot(T, B, S->m, S->n, l, e);
  }

  for (int k = 0; k < S->m; k++)
  {
    int i = B[k];
    if (i >= S->n)
      continue;
    solution->x[i] = T[k][S->m + S->n];
  }
  solution->status = OPTIMAL;
  solution->z = T[S->m][S->n + S->m];
}
