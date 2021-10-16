#ifndef SOLVERS_H
#define SOLVERS_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tools.h"
void Rayleigh_method(double *matrix, int dimension[], double *lambda, double **vector);
void Sub_space_method(double *matrix, int *dimension_matrix, double **lambda, double **vector, int n);
#endif
