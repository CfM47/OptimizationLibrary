#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

#include "optimization.h"

double *linear_regression(double *x, double *y, double (**f)(double), int n, int m);