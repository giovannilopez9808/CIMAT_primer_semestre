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
    double *matrix, *vector = NULL;
    double lambda = 0;
    int dimension_matrix[2],
        dimension_vector[2] = {1, 1};
    file_matrix = fopen(path_data, "r");
    valid_file(file_matrix);
    // Lectura de los datos de la matriz
    read_dimension(file_matrix,
                   dimension_matrix);
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
    dimension_vector[0] = dimension_matrix[0];
    (void)dimension_vector;
    obtain_max_eigenvalue(matrix,
                          dimension_matrix,
                          &lambda,
                          &vector);
    print_lines();
    printf("\nlambda = %lf\n\n", lambda);
    print_lines();
    printf("\nVector asociado\n\n");
    print_matrix(vector,
                 dimension_vector);
    free(matrix);
    free(vector);
    return 0;
}