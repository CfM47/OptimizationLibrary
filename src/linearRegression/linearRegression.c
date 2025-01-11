#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

#include "optimization.h"

double dot_func2func(double (*f)(double), double (*g)(double), const double *x, int n)
{
  double result = 0.0;
  for (int k = 0; k < n; k++)
    result += f(x[k]) * g(x[k]);
  return result;
}

double dot_func2vec(double (*f)(double), const double *x, const double *y, int n)
{
  double result = 0.0;
  for (int k = 0; k < n; k++)
    result += f(x[k]) * y[k];
  return result;
}

double *linear_regression(
    double *x,
    double *y,
    double (**f)(double),
    int n,
    int m)
{
  double **A = double_allocate_matrix(m, m);
  double *b = double_allocate_array(m);

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
      A[i][j] = dot_func2func(f[i], f[j], x, n);
  }

  for (int i = 0; i < m; i++)
    b[i] = dot_func2vec(f[i], x, y, n);

  double *c = solve_system(A, b, m);

  double_free_matrix(A, m);
  free(b);

  return c;
}