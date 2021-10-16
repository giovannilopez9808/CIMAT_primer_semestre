#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Functions/tools.h"
#include "../Functions/solvers.h"
void valid_number_of_eigen(int number_of_eigen, int *dimension)
{
    if (number_of_eigen > dimension[0] || number_of_eigen == 1)
    {
        printf("Número invalido de eigen-pares\n");
        exit(1);
    }
}
int main(int argc, char *argv[])
{
    (void)argc;
    int dimension_matrix[2], number_of_eigen = atoi(argv[2]);
    char path_data[50] = "../Data/";
    char path_output[50] = "Output/";
    strcat(path_data, argv[1]);
    strcat(path_output, argv[1]);
    FILE *file_matrix, *file_output;
    double *matrix, *lambda = NULL, *vectors = NULL;
    file_matrix = fopen(path_data, "r");
    valid_file(file_matrix);
    // Lectura de los datos de la matriz
    read_dimension(file_matrix,
                   dimension_matrix);
    valid_number_of_eigen(number_of_eigen,
                          dimension_matrix);
    file_output = fopen(path_output, "w");
    valid_file(file_output);
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
    Sub_space_method(matrix,
                     dimension_matrix,
                     &lambda,
                     &vectors,
                     number_of_eigen);
    print_several_results(file_output,
                          lambda,
                          vectors,
                          dimension_matrix,
                          number_of_eigen);
    printf("Archivo de resultados creado con exito.\nPath: \t%s\n",
           path_output);
    fclose(file_output);
    fclose(file_matrix);
    free(matrix);
    free(lambda);
    free(vectors);
    return 0;
}
