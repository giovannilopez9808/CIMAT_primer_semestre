#ifndef SOLVERS_H
#define SOLVERS_H
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void obtain_n_max_eigenvalue(double *matrix, int dimension_matrix[], double **lambda, double **vectors, int n_lambdas);
void obtain_n_min_eigenvalue(double *matrix, int dimension_matrix[], double **lambda, double **vectors, int n_lambdas);
void obtain_eigenvalues_jacobi(double *matrix, int dimension[], double **lambda, double **vectors);
#endif
