#ifndef spline_H
#define spline_H
#include <stdlib.h>
double *evaluate_f(double (*f)(double), double *x, int n);
void spline_line(double *x, double *y, double **m, double **b, int n);
double *evaluate_spline(double *x, int n, double *x_data, double *m, double *b, int n_data);
#endif