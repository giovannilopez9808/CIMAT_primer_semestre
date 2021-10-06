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
    char path_output[50] = "Output/";
    strcat(path_data, argv[1]);
    strcat(path_output, argv[1]);
    FILE *file_matrix, *file_output;
    double *matrix, *lambda = NULL, *vectors = NULL;
    int dimension_matrix[2];
    file_matrix = fopen(path_data, "r");
    file_output = fopen(path_output, "w");
    valid_file(file_matrix);
    valid_file(file_output);
    // Lectura de los datos de la matriz
    read_dimension(file_matrix,
                   dimension_matrix);
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
    int n = dimension_matrix[0] - 4;
    if (n < 2)
        n = 2;
    obtain_n_min_eigenvalue(matrix,
                            dimension_matrix,
                            &lambda,
                            &vectors,
                            n);
    print_several_results(file_output,
                          lambda,
                          vectors,
                          dimension_matrix,
                          n);
    printf("Archivo de resultados creado con exito.\nPath: \t%s\n",
           path_output);
    fclose(file_output);
    free(matrix);
    free(vectors);
    free(lambda);
    return 0;
}