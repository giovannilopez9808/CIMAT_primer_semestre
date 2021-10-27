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
#endif