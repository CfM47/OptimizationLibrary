#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

#include "optimization.h"

typedef struct
{
  int n;
  double **LU; // LU decomposition in situ of A
  int *P;
} PLU;

PLU *plu_decomposition(double **A, int n);
void plu_free(PLU *lu);
double *plu_solve(PLU plu, double *b);
double *solve_system(double **A, double *b, int n);