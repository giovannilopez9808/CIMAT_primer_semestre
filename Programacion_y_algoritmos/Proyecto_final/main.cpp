#include <iostream>
#include "Modules/tensor.h"

void f1(Tensor<double> &val)
{
    Tensor<double> b(val);
    std::cout << "Hola" << std::endl;
}
int main()
{
    size_t cols = 10;
    size_t rows = 20;
    size_t ranks = 30;
    double *t = new double[cols * rows * ranks];
    Tensor<double> a;
    Tensor<double> b(t, ranks, cols, rows);
    Tensor<double> c(t, ranks, cols, rows);
    f1(c);
    std::cout << "" << std::endl;
}
