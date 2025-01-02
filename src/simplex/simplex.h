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

SimplexSolution *simplex(StandardForm *S);

#endif // SIMPLEX_H