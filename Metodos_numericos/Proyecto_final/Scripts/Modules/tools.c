#include "tools.h"
void write_results(char *output_filename, int m, int n, double *table)
{
  int i, j;
  FILE *output;
  // Apertura del archivo
  output = fopen(output_filename, "wt");
  if (!output)
  {
    printf("\n");
    printf("write_results - Error\n");
    printf("\tNo pudo generarse el archivo\n");
    return;
  }
  // Escritura de la informacion
  for (j = 0; j < n; j++)
  {
    for (i = 0; i < m; i++)
    {
      fprintf(output, "  %lf", table[i + j * m]);
    }
    fprintf(output, "\n");
  }
  // Cierre del archivo
  fclose(output);
  return;
}
/*
  Creacion de una serie de elementos dado su elemento inicial, final y el numero de elementos totales de la serie
 */
double *linspace(double a, double b, int n)
{
  double *x = (double *)malloc(n * sizeof(double));

  for (int i = 0; i < n; i++)
  {
    x[i] = ((double)(n - i - 1) * a + (double)(i)*b) / (double)(n - 1);
  }
  return x;
}