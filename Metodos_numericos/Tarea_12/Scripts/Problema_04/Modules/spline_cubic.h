#ifndef spline_cubic_H
#define spline_cubic_H
#include <math.h>
void obtain_parameters(double *x, double *y, double **b, double **c, double **d, int n);
void spline_cubic_f(double *x, double **y, double *x_data, double *a, double *b, double *c, double *d, int n_data, int n);
#endif