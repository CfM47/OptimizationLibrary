#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

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

void pivot(double **T, int m, int n, int l, int e);
double **build_table(StandardForm *S);
int find_pivotColumn(double **T, int m, int n);
int find_pivotRow(double **T, int m, int n, int l);
SimplexSolution *simplex(StandardForm *S);

#endif // SIMPLEX_H