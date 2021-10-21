#include "Modules/matrix_system.h"
#include "Modules/functions.h"
#include "Modules/solvers.h"
int main()
{
    int n =2000 ;
    int n_lambda = 10;
    // Creacion de la matriz
    double *matrix = create_matrix_system(n);
    double *lambda_sup,
           *lambda_inf,
           *vectors_sup,
           *vectors_inf;
    int dimension[2] = {n, n};
    int dimension_vector[2] = {n, n_lambda};
    // Archivos de resultados
    char *path_lambda = "Output/lambda.vec";
    char *path_vector = "Output/vectors.mtx";
    FILE *output_lambda = open_file(path_lambda, "w");
    FILE *output_vector = open_file(path_vector, "w");
    // Obtiene los n maximos eigenvalores de la matriz dada
    obtain_n_max_eigenvalue(matrix,
                            dimension,
                            &lambda_sup,
                            &vectors_sup,
                            n_lambda);
    // Obtiene los n minimos eigenvalores de la matriz dada
    obtain_n_min_eigenvalue(matrix,
                            dimension,
                            &lambda_inf,
                            &vectors_inf,
                            n_lambda);
    // Imprime los resultados de la matriz
    print_lambdas_and_vectors(output_lambda,
                              output_vector,
                              lambda_sup,
                              lambda_inf,
                              vectors_sup,
                              vectors_inf,
                              dimension_vector,
                              n_lambda);
    return 0;
}
