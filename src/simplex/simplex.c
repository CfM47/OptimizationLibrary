#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

#include "optimization.h"

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

double **build_artificalTable(StandardForm *S)
{
  int m = S->m;
  int n = S->n;
  int rows = m + 1;
  int cols = n + m + 2;
  double **T = double_allocate_matrix(rows, cols);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      T[i][j] = S->A[i][j];
    T[i][n + i] = 1;
    T[i][n + m + 1] = S->b[i];
  }
  for (int i = 0; i < m; i++)
    T[i][n + m] = -1;
  for (int i = 0; i < n + m; i++)
    T[m][i] = 0;
  T[m][n + m] = 1;
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

SimplexSolution *findSolution(double **T, double *B, int m, int n)
{
  double *x = double_allocate_array(n);
  SimplexSolution *solution = malloc(sizeof(SimplexSolution));
  solution->x = x;

  int e;
  while ((e = find_pivotColumn(T, m, n)) >= 0)
  {
    int l = find_pivotRow(T, m, n, e);
    if (l == -1)
    {
      for (int i = 0; i < n; i++)
        solution->x[i] = INFINITY;

      solution->status = UNBOUNDED;
      solution->z = INFINITY;
      return solution;
    }
    pivot(T, B, m, n, l, e);
  }

  for (int k = 0; k < m; k++)
  {
    int i = B[k];
    if (i >= n)
      continue;
    solution->x[i] = T[k][m + n];
  }
  solution->status = OPTIMAL;
  solution->z = T[m][n + m];
}

SimplexSolution *simplex(StandardForm *S)
{

  int basic = 1;
  for (int i = 0; i < S->m; i++)
  {
    if (S->b[i] < 0)
    {
      basic = 0;
      break;
    }
  }
  if (basic)
  {
    double **T = build_table(S);
    double *B = double_allocate_array(S->m);
    for (int i = 0; i < S->m; i++)
      B[i] = S->n + i;
    return findSolution(T, B, S->m, S->n);
  }

  double **T = build_artificalTable(S);
  double *B = double_allocate_array(S->m);
  for (int i = 0; i < S->m; i++)
    B[i] = S->n + i;
  int l = -1;
  int min = 0;
  for (int i = 0; i < S->m; i++)
  {
    if (S->b[i] < min)
    {
      min = S->b[i];
      l = i;
    }
  }
  pivot(T, B, S->m, S->n + 1, l, S->n + S->m);
  SimplexSolution *solution = findSolution(T, B, S->m, S->n + 1);
  if (solution->z != 0)
  {
    solution->status = INFEASIBLE;
    for (int i = 0; i < S->n; i++)
      solution->x[i] = NAN;
    solution->z = NAN;
    return solution;
  }

  for (int j = 0; j < S->n; j++)
    T[S->m][j] = -S->c[j];
  for (int i = 0; i < S->m; i++)
    T[S->m][S->n + i] = 0;

  for (int i = 0; i <= S->m; i++)
    T[i][S->m + S->n] = T[i][S->m + S->n + 1];
  for (int k = 0; k < S->m; k++)
  {
    int i = B[k];
    if (i >= S->n)
      continue;
    int c_i = T[S->m][i];
    for (int j = 0; j <= S->n + S->m; j++)
      T[S->m][j] -= T[i][j] * c_i;
  }

  solution = findSolution(T, B, S->m, S->n);

  return solution;
}
