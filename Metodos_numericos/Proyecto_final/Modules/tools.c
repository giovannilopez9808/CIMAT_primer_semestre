#include "tools.h"
void r8mat_write(char *output_filename, int m, int n, double table[])
/*
  Purpose:
    R8MAT_WRITE writes an R8MAT file.
  Discussion:
    An R8MAT is an array of R8's.
  Parameters:
    Input, char *OUTPUT_FILENAME, the output filename.
    Input, int M, the spatial dimension.
    Input, int N, the number of points.
    Input, double TABLE[M*N], the table data.
*/
{
  int i, j;
  FILE *output;
  output = fopen(output_filename, "wt");

  if (!output)
  {
    printf("\n");
    printf("R8MAT_WRITE - Fatal error!\n");
    printf("  Could not open the output file.\n");
    return;
  }
  /*
    Write the data.
  */
  for (j = 0; j < n; j++)
  {
    for (i = 0; i < m; i++)
    {
      fprintf(output, "  %lf", table[i + j * m]);
    }
    fprintf(output, "\n");
  }
  /*
    Close the file.
  */
  fclose(output);

  return;
}
double *linspace(double a, double b, int n)
{
  double *x = (double *)malloc(n * sizeof(double));

  for (int i = 0; i < n; i++)
  {
    x[i] = ((double)(n - i - 1) * a + (double)(i)*b) / (double)(n - 1);
  }
  return x;
}