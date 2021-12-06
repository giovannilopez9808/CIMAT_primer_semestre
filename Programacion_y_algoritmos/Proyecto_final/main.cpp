#include "Modules/tensor.h"

int main()
{
    // Definicion del tamaño del tensor
    size_t cols = 3;
    size_t rows = 4;
    size_t ranks = 2;
    // Tensor raw creado
    double *t = new double[cols * rows * ranks];
    for (size_t i = 0; i < cols * rows * ranks; i++)
    {
        t[i] = i + 1;
    }
    // Inicializacion del tensor a partir de una lista
    Tensor<double> b(t, ranks, cols, rows);
    // Inicializacion de un tensor a partir de un tensor
    Tensor<double> c(b);
    // Calculo de la suma
    Tensor<double> suma = b + c;
    // Calculo de la resta
    Tensor<double> resta = b - c;
    // Calculo de la multiplicacion
    Tensor<double> multi = b * c;
    // Calculo de la division
    Tensor<double> division = b / c;
    std::cout << "====== Tensor a ======" << std::endl;
    b.print();
    std::cout << "====== Tensor b ======" << std::endl;
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
