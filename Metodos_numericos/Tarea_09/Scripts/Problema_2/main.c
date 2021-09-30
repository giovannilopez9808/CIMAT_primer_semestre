#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Functions/tools.h"
#include "../Functions/solvers.h"
int main(int argc, char *argv[])
{
    (void)argc;
    char path_data[50] = "../Data/";
    char path_out[50] = "Output/";
    strcat(path_data, argv[1]);
    strcat(path_out, argv[1]);
    FILE *file_matrix;
    double *matrix, *lambda = NULL, *vector = NULL;
    int dimension_matrix[2];
    file_matrix = fopen(path_data, "r");
    valid_file(file_matrix);
    // Lectura de los datos de la matriz
    read_dimension(file_matrix,
                   dimension_matrix);
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
    int n = dimension_matrix[0] - 2;
    if (n < 2)
        n = 2;
    obtain_n_max_eigenvalue(matrix,
                            dimension_matrix,
                            &lambda,
                            &vector,
                            n);
    // print_lines();
    // printf("\nlambda_max = %lf\n\n", lambda_max);
    // print_lines();
    // printf("\nVector asociado\n\n");
    // print_matrix(vector,
    //              dimension_vector);
    free(matrix);
    free(vector);
    free(lambda);
    return 0;
}