#include <string.h>
#include "Modules/tools.h"
#include "Modules/solver.h"
int main(int argv, char *argc[])
{
    (void)argv;
    // Direccion de los archivos
    char path_data[50] = "Data/";
    // Direccion de los outputs
    char path_vector_output[50] = "Output/vector_";
    char path_lambda_output[50] = "Output/lambda_";
    // Caracterizacion del nombre de los archivos
    strcat(path_data, argc[1]);
    strcat(path_vector_output, argc[1]);
    strcat(path_lambda_output, argc[1]);
    // Inicializacion de los output e inputs
    FILE *data = open_file(path_data, "r");
    FILE *file_lambda = open_file(path_lambda_output, "w");
    FILE *file_vector = open_file(path_vector_output, "w");
    // Inicializacion de las matrices
    double *matrix, *lambda, *vectors;
    int dimension_matrix[2], dimension_vector[2];
    // Lectura de la informacion de la matriz
    read_dimension(data,
                   dimension_matrix);
    read_matrix(data,
                dimension_matrix,
                &matrix);
    // Caracterizacion de la dimension de los vectores
    dimension_vector[0] = dimension_matrix[0];
    dimension_vector[1] = 1;
    // Obtiene los eigenpares usando QR
    obtain_eigen_with_QR(matrix,
                         &lambda,
                         &vectors,
                         dimension_matrix);
    //  Guarda los resultados de eigenvalores
    print_file_matrix(file_lambda,
                      lambda,
                      dimension_vector);
    //   Guarda los resultados de los eigenvectores
    print_file_matrix(file_vector,
                      vectors,
                      dimension_matrix);
    free(matrix);
    free(lambda);
    free(vectors);
    fclose(data);
    fclose(file_lambda);
    fclose(file_vector);
    return 0;
}
