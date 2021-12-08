#ifndef tools_H
#define tools_H
#include <stdlib.h>
#include <stdio.h>
void write_results(char *output_filename, int m, int n, double *table);
double *linspace(double a, double b, int n);
#endif