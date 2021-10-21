#ifndef functions_H
#define functions_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void print_matrix(double *matrix, int *dimension_matrix);
void identity_matrix(double *matrix, int *dimension);
void obtain_vector_i(double *vectors, double *vector, int *dimension, int n);
void save_vector(double **vectors, double *vector, int *dimension, int n);
void write_results(FILE *output, double *matrix, int *dimension);
double obtain_norm(double *vector, int *dimension);
void obtain_multiplication_matrix(double *A, double *B, double *AB, int *dimension_matrix_A, int *dimension_matrix_B);
double obtain_cdot_multiplication(double *vector1, double *vector2, int *dimension);
void Fill_initial_values_U_matrix(double *U, int *dimension_matrix);
void solve_triangular_superior_matrix(double *matrix, int *dimension_matrix, double *results, double **solutions);
void solve_triangular_inferior_matrix(double *matrix, int *dimension_matrix, double *results, double **solutions);
void print_lines();
#endif