#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "optimization.h"

// Definición de funciones base
double f0(double x) { return 1; }
double f1(double x) { return x; }
double f2(double x) { return x * x; }
double f3(double x) { return x * x * x; }
double f4(double x) { return x * x * x * x; }
double f5(double x) { return x * x * x * x * x; }
double f6(double x) { return x * x * x * x * x * x; }
double f7(double x) { return x * x * x * x * x * x * x; }
double f8(double x) { return x * x * x * x * x * x * x * x; }
double f9(double x) { return x * x * x * x * x * x * x * x * x; }
double f10(double x) { return x * x * x * x * x * x * x * x * x * x; }

double random_noise(double min, double max)
{
  return min + (rand() / (double)RAND_MAX) * (max - min);
}

int main()
{
  int n = 100;
  const int m = 10;
  double coef[m];

  double x[n];
  double (*f[11])(double) = {f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10};

  for (int i = 0; i < n; i++)
    x[i] = i;

  for (int i = 0; i < m; i++)
  {
    coef[i] = random_noise(-10, 10);
  }

  double y[n];
  for (int i = 0; i < n; i++)
  {
    y[i] = 0;
    for (int j = 0; j < m; j++)
      y[i] += coef[j] * f[j](x[i]);
    y[i] += random_noise(-200, 200);
    // y[i] = random_noise(-100, 100);
  }

  double *c = linear_regression(x, y, f, n, m);

  printf("Puntos x\n[");
  for (int i = 0; i < n; i++)
    printf("%f, ", x[i]);
  printf("]\n\n");

  printf("Puntos y\n[");
  for (int i = 0; i < n; i++)
    printf("%f, ", y[i]);
  printf("]\n\n");

  printf("Coeficientes obtenidos:\n");
  for (int i = 0; i < m; i++)
    printf("%f, ", c[i]);
  printf("\n");

  return 0;
}
