#ifndef SOLVERS_H
#define SOLVERS_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tools.h"
/* 
    Copia los valores del vector en el vector i
     */
void copy_vector(double *vector, double *vector_i, int dimension[]);
/* 
    Inicializa el vector dado con el valor 1/sqrt(n) en todos sus elementos
     */
void initialize_vector(double *vector, int dimension[]);
/* 
    Compara los valores de lambda para ver si se llega a una convergencia del metodo
     */
int convergence_eigenvalues(double lambda, double lambda_i, int attempt);
/* 
    Metodo de las potencias, recibe una matriz y su dimension y devuelve su eigenvalor dominante con su respectito eigenvector
     */
void obtain_max_eigenvalue(double *matrix, int dimension_matrix[], double *lambda, double **vector);
/* 
    Copia del vector i en la matriz de eigenvectores
     */
void copy_vector_i(double *vectors, double *vector, int dimension[], int n);
/* 
    Eliminacion de las contribuciones de los eigenvalores anteriores a el nuevo vector
     */
void obatin_new_vector(double **vector, double *vectors, int dimension[], int n);
/* 
    Copia del vector en la matriz de vectores unitarios
     */
void copy_vectors(double **vectors, double *vector, int dimension[], int n);
/* 
Metodo de deflaccion, dada una matriz y su dimension se calcularan los n lambdas dadas maximas
*/
void obtain_n_max_eigenvalue(double *matrix, int dimension_matrix[], double **lambda, double **vectors, int n_lambdas);
/* 
dada una matrix y su tamaño obtiene el eigenvalor menor absoluto y su respectivo eigenvector
*/
void obtain_min_eigenvalue(double *matrix, int dimension_matrix[], double *lambda, double **vector);
#endif