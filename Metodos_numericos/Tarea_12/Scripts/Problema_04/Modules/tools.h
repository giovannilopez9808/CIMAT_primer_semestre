#ifndef function_H
#define function_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void create_points(double xi, double xf, double **x, int n);
void obtain_points(double **x, double **y, int n);
double *create_identity_matrix(int *dimension);
void obtain_LU_crout(double *matrix, int dimension_matrix[], double **L, double **U);
void solve_with_LU(double *L, double *U, int *dimension, double *results, double **solutions);
void print_results(FILE *file, double *x, double *y, int n);
#endif