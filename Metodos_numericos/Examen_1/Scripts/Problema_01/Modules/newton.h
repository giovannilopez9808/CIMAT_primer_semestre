#ifndef newton_H
#define newton_H
#include <math.h>
#include <stdio.h>
#include "functions.h"
void newton_method(double (*f)(double), double tol_x, double tol_f, double x0);
#endif