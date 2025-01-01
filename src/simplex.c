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

// T es la tabla del simplex
// | -c 0 0 |
// | A  I b |
// n es el número de variables
// m es el número de restricciones

// e y l son las variables de entrada y salida respectivamente
void pivot(double **T, int m, int n, int l, int e)
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
  int e = 0;
  for (int j = 0; j < n + m; j++)
    if (T[m][j] < T[m][e])
      e = j;
  if (T[m][e] >= 0)
    return -1;
  return e;
}

int find_pivotRow(double **T, int m, int n, int l)
{
  int e = 0;
  double minRatio = DBL_MAX;
  for (int i = 0; i < m; i++)
  {
    if (T[i][l] <= 0)
      continue;
    double b_i = T[i][n + m];
    double a_il = T[i][l];
    double a_el = T[e][l];
    if (minRatio > b_i / a_il)
    {
      e = i;
      minRatio = b_i / a_il;
    }
  }
  return e;
}

SimplexSolution *simplex(StandardForm *S)
{
  double *x = double_allocate_array(S->n);
  SimplexSolution *solution = malloc(sizeof(SimplexSolution));
  solution->x = x;

  double **T = build_table(S);
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
    pivot(T, S->m, S->n, l, e);
  }

  for (int i = 0; i < S->m; i++)
    solution->x[i] = T[i][S->n + S->m];
  solution->status = OPTIMAL;
  solution->z = T[S->m][S->n + S->m];
}
