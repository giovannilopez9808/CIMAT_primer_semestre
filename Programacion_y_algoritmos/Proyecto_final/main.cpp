#include <iostream>
#include "Modules/tensor.h"

void f1(Tensor<double> &val)
{
    Tensor<double> b(val);
    size_t rows = val.get_rows();
    size_t cols = val.get_cols();
    size_t ranks = val.get_ranks();
    double *data = val.get_data();
    for (int i = 0; i < rows * cols * ranks; i++)
    {
        std::cout << i;
        std::cout << " ";
        std::cout << rows * cols * ranks;
        std::cout << " ";
        std::cout << data[i] << std::endl;
    }
}
int main()
{
    size_t cols = 10;
    size_t rows = 20;
    size_t ranks = 30;
    double *t = new double[cols * rows * ranks];
    // for (int i = 0; i < cols * rows * ranks; i++)
    // {
    //     std::cout << t[i] << std::endl;
    // }
    Tensor<double> a;
    Tensor<double> b(t, ranks, cols, rows);
    Tensor<double> c(t, ranks, cols, rows);
    f1(a);
}
