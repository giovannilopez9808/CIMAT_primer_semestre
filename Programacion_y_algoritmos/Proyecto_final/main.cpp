#include <iostream>
#include "Modules/tensor.h"

int main()
{
    size_t cols = 3;
    size_t rows = 4;
    size_t ranks = 2;
    double *t = new double[cols * rows * ranks];
    for (size_t i = 0; i < cols * rows * ranks; i++)
    {
        t[i] = i + 1;
    }
    Tensor<double> b(t, ranks, cols, rows);
    Tensor<double> c(b);
    Tensor<double> suma = b + c;
    Tensor<double> resta = b - c;
    Tensor<double> multi = b * c;
    Tensor<double> division = b / c;
    std::cout << "====== Matriz a ======" << std::endl;
    b.print();
    std::cout << "====== Matriz b ======" << std::endl;
    c.print();
    std::cout << "====== Suma ======" << std::endl;
    suma.print();
    std::cout << "====== Resta ======" << std::endl;
    resta.print();
    std::cout << "====== Multiplicacion ======" << std::endl;
    multi.print();
    std::cout << "====== Division ======" << std::endl;
    division.print();
}
