#include "tools.h"
void write_results(FILE *output, int n, double result)
{
    fprintf(output, "%d,%lf\n", n, result);
}
FILE *open_file(char *filename, char *mode)
{
    /*
    Validacion del archivo
     */
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("File error\n");
        exit(1);
    }
    return file;
}