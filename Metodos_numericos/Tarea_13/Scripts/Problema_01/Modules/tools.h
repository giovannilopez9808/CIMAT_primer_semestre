#ifndef tools_H
#define tools_H
#include <stdlib.h>
#include <stdio.h>
FILE *open_file(char *filename, char *mode);
void write_results(FILE *output, int n, double result);
#endif