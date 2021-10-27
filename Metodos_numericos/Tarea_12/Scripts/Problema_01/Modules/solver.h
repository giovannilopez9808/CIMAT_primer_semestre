#ifndef solver_H
#define solver_H
#include "qr.h"
void obtain_eigen_with_QR(double *matrix, double **lambda, double **vectors, int *dimension);
#endif