#ifndef tools_H
#define tools_H
#include <stdlib.h>
#include <stdio.h>
void r8mat_write(char *output_filename, int m, int n, double *table);
double *linspace(double a, double b, int n);
#endif