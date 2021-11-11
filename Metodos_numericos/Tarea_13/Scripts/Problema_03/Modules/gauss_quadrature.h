#ifndef gauss_quadrature_H
#define gauss_quadrature_H
double integrate_with_gauss(double (*f)(double), double b, double a, int n);
#endif