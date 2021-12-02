#include <iostream>
#include "Modules/tensor.h"

int main()
{
    size_t cols = 10;
    size_t rows = 20;
    size_t ranks = 30;
    double *t = new double[cols * rows * ranks];
    for (int i = 0; i < cols * rows * ranks; i++)
    {
        t[i]=i;
    }
    Tensor<double> b(t, ranks, cols, rows);
    Tensor<double> c(b);
    for (int i = 0; i < rows * cols * ranks; i++)
    {
        std::cout << i;
        std::cout << " ";
        std::cout << rows * cols * ranks;
        std::cout << " ";
        std::cout << c.get_data()[i] << std::endl;
    }
}
