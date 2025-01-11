#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "optimization.h"

// Definición de funciones base
double f0(double x) { return 1; }
double f1(double x) { return x; }
double f2(double x) { return x * x; }

double random_noise(double min, double max)
{
  return min + (rand() / (double)RAND_MAX) * (max - min);
}

int main()
{
  double x1[] = {0, 1, 2, 3, 4};
  double y1[] = {2, 4, 6, 8, 10};
  double (*basis1[])(double) = {f0, f1};
  int n1 = 5, m1 = 2;
  double *c1 = linear_regression(x1, y1, basis1, n1, m1);
  printf("Caso 1: c = [%.2f, %.2f]\n", c1[0], c1[1]);
  free(c1);

  double x2[] = {0, 1, 2, 3, 4};
  double y2[5];
  for (int i = 0; i < 5; i++)
    y2[i] = 3 * x2[i] + 5;

  double (*basis2[])(double) = {f0, f1};
  int n2 = 5, m2 = 2;
  double *c2 = linear_regression(x2, y2, basis2, n2, m2);
  printf("Caso 2: c = [%.2f, %.2f]\n", c2[0], c2[1]);
  free(c2);

  double x3[] = {0, 1, 2, 3, 4};
  double y3[5];
  for (int i = 0; i < 5; i++)
    y3[i] = x3[i] * x3[i] - 3 * x3[i] + 2;
  double (*basis3[])(double) = {f0, f1, f2};
  int n3 = 5, m3 = 3;
  double *c3 = linear_regression(x3, y3, basis3, n3, m3);
  printf("Caso 3: c = [%.2f, %.2f, %.2f]\n", c3[0], c3[1], c3[2]);
  free(c3);

  return 0;
}
