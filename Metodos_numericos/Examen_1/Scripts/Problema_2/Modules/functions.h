#ifndef functions_H
#define functions_H
#include <stdlib.h>
#include <stdio.h>
void read_matrix(FILE *file, int dimension[], double **matrix);
void read_dimension(FILE *file, int dimension[]);
FILE *open_file(char *filename, char *mode);
void print_matrix(double *matrix, int *dimension_matrix);
void identity_matrix(double *matrix, int *dimension);
void obtain_vector_i(double *vectors, double *vector, int *dimension, int n);
void save_vector(double **vectors, double *vector, int *dimension, int n);
void print_lines();
#endif