#include <string.h>
#include "Modules/tools.h"
#include "Modules/solver.h"
int main(int argv, char *argc[])
{
    (void)argv;
    char path_data[50] = "Data/";
    strcat(path_data, argc[1]);
    FILE *data = open_file(path_data, "r");
    double *matrix, *lambda, *vectors;
    int dimension[2];
    read_dimension(data,
                   dimension);
    read_matrix(data,
                dimension,
                &matrix);
    obtain_eigen_with_QR(matrix,
                         &lambda,
                         &vectors,
                         dimension);
    free(matrix);
    free(lambda);
    free(vectors);
    fclose(data);
    return 0;
}
