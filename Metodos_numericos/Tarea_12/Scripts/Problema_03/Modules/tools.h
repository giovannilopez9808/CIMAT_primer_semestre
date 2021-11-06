#ifndef tools_H
#define tools_H
#include <stdlib.h>
#include <stdio.h>
FILE *open_file(char *filename, char *mode);
void print_results(FILE *file, double *x, double *y, int n);
double *linspace(double xi, double xf, int n);
double *evaluate_f(double (*f)(double), double *x, int n);
#endif