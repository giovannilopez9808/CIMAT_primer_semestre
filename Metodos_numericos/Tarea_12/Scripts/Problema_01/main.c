#include <string.h>
#include "Modules/tools.h"
#include "Modules/solver.h"
int main(int argv, char *argc[])
{
    (void)argv;
    char path_data[50] = "Data/";
    char path_vector_output[50] = "Output/vector_";
    char path_lambda_output[50] = "Output/lambda_";
    strcat(path_data, argc[1]);
    strcat(path_vector_output, argc[1]);
    strcat(path_lambda_output, argc[1]);
    FILE *data = open_file(path_data, "r");
    FILE *file_lambda = open_file(path_vector_output, "w");
    FILE *file_vector = open_file(path_lambda_output, "w");
    double *matrix, *lambda, *vectors;
    int dimension_matrix[2], dimension_vector[2];
    read_dimension(data,
                   dimension_matrix);
    read_matrix(data,
                dimension_matrix,
                &matrix);
    dimension_vector[0] = dimension_matrix[0];
    dimension_vector[1] = 1;
    obtain_eigen_with_QR(matrix,
                         &lambda,
                         &vectors,
                         dimension_matrix);
    print_file_matrix(file_lambda,
                      lambda,
                      dimension_vector);
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
