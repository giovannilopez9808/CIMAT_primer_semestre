#ifndef tools_H
#define tools_H
#include <stdlib.h>
#include <stdio.h>
FILE *open_file(char *filename, char *mode);
void read_dimension(FILE *file, int *dimension);
void read_matrix(FILE *file, int *dimension, double **matrix);
void print_matrix(double *matrix, int *dimension);
void obtain_vector_i(double *vectors, double *vector, int *dimension, int n);
double obtain_cdot_multiplication(double *vector1, double *vector2, int *dimension);
void copy_matrix(double *matrix, double *matrix_copy, int *dimension);
double *obtain_multiplication_vvT(double *vector, int *dimension);
void obtain_multiplication_matrix(double *A, double *B, double *AB, int *dimension_matrix_A, int *dimension_matrix_B);
double *create_identity_matrix(int *dimension);
#endif