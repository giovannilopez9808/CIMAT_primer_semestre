#ifndef solver_H
#define solver_H
#include "qr.h"
#include "eigen.h"
void obtain_eigen_with_QR(double *matrix, double **lambda, double **vectors, int *dimension);
#endif