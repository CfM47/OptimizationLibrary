#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

#include "optimization.h"

PLU *plu_decomposition(double **A, int n)
{
  double **a = double_allocate_matrix(n, n);
  double_copy_matrix(a, A, n, n);

  int *p = int_allocate_array(n);
  for (int i = 0; i < n; i++)
    p[i] = i;
  int kp = 0;
  for (int k = 0; k < n; k++)
  {
    double pivot = 0;
    for (int i = k; i < n; i++)
    {
      if (fabs(a[i][k]) > pivot)
      {
        pivot = fabs(a[i][k]);
        kp = i;
      }
    }
    if (pivot == 0)
    {
      printf("Matrix is singular\n");
      exit(1);
    }
    int_swap(&p[k], &p[kp]);
    for (int i = 0; i < n; i++)
      double_swap(&a[k][i], &a[kp][i]);
    for (int i = k + 1; i < n; i++)
    {
      a[i][k] = a[i][k] / a[k][k];
      for (int j = k + 1; j < n; j++)
        a[i][j] -= a[i][k] * a[k][j];
    }
  }

  PLU *lu = (PLU *)malloc(sizeof(PLU));
  lu->n = n;
  lu->LU = a;
  lu->P = p;
  return lu;
}

void plu_free(PLU *lu)
{
  double_free_matrix(lu->LU, lu->n);
  free(lu->P);
  free(lu);
}

double *plu_solve(PLU plu, double *b)
{
  int n = plu.n;
  double *x = double_allocate_array(n);
  double *y = double_allocate_array(n);

  for (int i = 0; i < n; i++)
  {
    double b_pi = b[plu.P[i]];
    y[i] = b_pi;
    for (int j = 0; j < i; j++)
      y[i] -= plu.LU[i][j] * y[j];
  }
  for (int i = n - 1; i >= 0; i--)
  {
    x[i] = y[i];
    for (int j = i + 1; j < n; j++)
      x[i] -= plu.LU[i][j] * x[j];
    x[i] /= plu.LU[i][i];
  }
  free(y);
  return x;
}

double *solve_system(double **A, double *b, int n)
{
  PLU *lu = plu_decomposition(A, n);
  double *x = plu_solve(*lu, b);
  plu_free(lu);
  return x;
}