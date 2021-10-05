#ifndef TOOLS_H
#define TOOLS_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/* 
    Realiza la impresion de las lineas en la terminal
     */
void print_lines();
void print_matrix(double *matrix, int dimension_matrix[]);
/* 
    Realiza la impresion de las lineas en el documento
     */
void print_lines_on_file(FILE *text);
/*
    Realiza la validacion del sistema de ecuaciones lineales
     */
void valid_solution(double number);
/*
    Validacion del archivo
     */
void valid_file(FILE *text_file);
/*
    Lectura de las dimensiones de la matriz a partir de un archivo dado
    inputs:
    + file: puntero del archivo
    + dimension: arreglo de dimension 2 de tipo entero
     */
void read_dimension(FILE *file, int dimension[]);
/*
    Lectura de los datos de la matriz a partir de un archivo dado
    inputs:
    + file: puntero del archivo
    + dimension: arreglo de dimension 2 de tipo entero
    + matrix: doble puntero de un tipo de dato double donde se alojaran los datos de la matriz
     */
void read_matrix(FILE *file, int dimension[], double **matrix);
/*
    Realiza la multiplicacion de matrices
     */
void obtain_multiplication_matrix(double *A, double *B, double *AB, int dimension_matrix_A[], int dimension_matrix_B[]);
/* 
    Calcula la norma de un vector dado
     */
double obtain_norm(double *vector, int dimension[]);
/* 
    Realiza la normalizacion del vector dado
     */
void normalize_vector(double *vector, int dimension[]);
/* 
    Realiza la multiplicacion de un vector por su transpuesta, dando como
    restultado una matriz de nxn
     */
void obtain_multiplication_vvT(double *vector, int dimension[], double **matrix);
/* 
    Realiza el producto punto de dos vectores dados
     */
double obtain_cdot_multiplication(double *vector1, double *vector2, int dimension[]);
double obtain_Frobenius_norm(double *matrix, int dimension[]);
/* 
    Realiza la impresion en un archivo de un vector en una sola fila
     */
void print_eigenvector_on_a_file(FILE *text, double *vectors, int *dimension);
void print_lambdas_on_a_file(FILE *text, double *lambda, int n);
/* 
    Realiza la impresion de el eigenvalor dado en un archivo
     */
void print_lambda_on_a_file(FILE *text, double lambda);
/* 
    Realiza la impresion de los resultados de un eigenvalor y un eigen vector
     */
void print_results(FILE *text, double lambda, double *vectors, int *dimension);
/* 
    Realiza la impresion de un conjunto de eigenvalores y eigenvectores
     */
void print_several_results(FILE *text, double *lambda, double *vectors, int *dimension, int n);
/*
    Inicializa la matrix U con unos en la diagonal
    inputs:
    + U: puntero del arreglo de la matriz U
    + dimension_matrix: arreglo de dos dimensiones que contiene el tamaño de la matriz
     */
void Fill_initial_values_U_matrix(double *U, int dimension_matrix[]);
/*
    Valida que la diagonal de la matriz L es diferente de cero
     */
void validate_l_ii(double l_ii);
/*
    Aplica la factorizacion LU aplicando la version de Crout
    inputs:
    + matrix: puntero del arreglo que contiene lo datos de la matriz
    + dimension_matrix: puntero del arreglo de dos dimensiones que contiene el tamaño de la matriz
    + L: doble puntero que contendra la matriz L
    + U: doble puntero que contendra la matriz U
     */
void obtain_LU_crout(double *matrix, int dimension_matrix[], double **L, double **U);
/*
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular superior
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
void solve_triangular_superior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions);
/*
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular inferior
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
void solve_triangular_inferior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions);
/*
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz diagonal
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
void solve_diagonal_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions);
/*
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular superior
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
void solve_gaussian_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions);
#endif