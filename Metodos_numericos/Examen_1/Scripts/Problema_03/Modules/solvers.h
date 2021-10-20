#ifndef solvers_H
#define solvers_H
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
void solve_triangular_superior_matrix(double *matrix, int *dimension_matrix, double *results, double **solutions);
void solve_triangular_inferior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions);
void solve_triangular_superior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions);
void solve_diagonal_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions);
#endif