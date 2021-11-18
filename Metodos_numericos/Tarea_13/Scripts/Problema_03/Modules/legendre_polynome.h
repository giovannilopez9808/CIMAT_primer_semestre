#ifndef legendre_H
#define legendre_H
#include <stdlib.h>
#include <math.h>
#define pi 3.141592653589793
double legende_polynome(double x, int n);
double obtain_ai(int i, int n);
double *obtain_roots(int n);
double obtain_derivate(double x, int i);
double *obtain_weight(int n);
#endif
