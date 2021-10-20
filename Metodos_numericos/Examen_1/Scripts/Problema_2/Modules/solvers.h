#ifndef solvers_H
#define solvers_H
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
void solve_gaussian_matrix(double *matrix, int *dimension_matrix, double *results, double **solutions);
void solve_triangular_superior_matrix(double *matrix, int *dimension_matrix, double *results, double **solutions);
void obtain_LU_crout(double *matrix, int dimension_matrix[], double **L, double **U);
void solve_triangular_inferior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions);
void solve_triangular_superior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions);
void solve_with_LU(double *L, double *U, int *dimension, double *results, double **solutions);
void obtain_matrix_inverse(double *L, double *U, int *dimension, double **matrix_inverse);
#endif