#ifndef tensor_H
#define tensor_H
#include <iostream>
#include <memory>
// Definicion de la clase Tensor
template <typename type>
class Tensor
{
private:
    // Valores del tensor
    std::shared_ptr<type[]> data;
    // Numero de rango
    size_t ranks;
    // Numero de columnas
    size_t cols;
    // Numero de filas
    size_t rows;
    // Definicion de la operacion suma
    Tensor<type> sum(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);

    // Definicion de la operacion resta
    Tensor<type> diff(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);

    // Definicion de la operacion multiplicacion
    Tensor<type> mult(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);

    // Definicion de la operacion division
    Tensor<type> div(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);

public:
    // Constructor vacio
    Tensor();
    // Constructor dado una lista y su tamaño
    Tensor(type *data_input,
           size_t ranks_input,
           size_t cols_input,
           size_t rows_input);
    // Constructor dado el tamaño
    Tensor(size_t ranks_input,
           size_t cols_input,
           size_t rows_input);
    // Constructor dado el tamaño como matriz
    Tensor(size_t cols_input,
           size_t row_inputs);
    //    Constructor dado un tensor
    Tensor(const Tensor &copy);
    // Definicion de la suma con el operador +
    Tensor<type> operator+(const Tensor<type> &operand);
    // Definicion de la multiplicacion con el operador *
    Tensor<type> operator*(const Tensor<type> &operand);
    // Definicion de la resta con el operador -
    Tensor<type> operator-(const Tensor<type> &operand);
    // Definicion de la division con el operador /
    Tensor<type> operator/(const Tensor<type> &operand);
    // Obtiene el numero de rango
    size_t get_ranks();
    // Obtiene el numero de columnas
    size_t get_cols();
    // Obtiene el numero de filas
    size_t get_rows();
    // Obtiene los datos
    type *get_data();
    // Imprime el tensor
    void print();
    // Destructor
    ~Tensor();
};

template <typename type>
Tensor<type> Tensor<type>::operator+(const Tensor<type> &operand)
{
    return sum(data, operand.data);
}

template <typename type>
Tensor<type> Tensor<type>::operator*(const Tensor<type> &operand)
{
    return mult(data, operand.data);
}

template <typename type>
Tensor<type> Tensor<type>::operator-(const Tensor<type> &operand)
{
    return diff(data, operand.data);
}

template <typename type>
Tensor<type> Tensor<type>::operator/(const Tensor<type> &operand)
{
    return div(data, operand.data);
}

template <typename type>
type *Tensor<type>::get_data()
{
    return data.get();
}

template <typename type>
Tensor<type> Tensor<type>::sum(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
{
    // Obtiene el valor del primer tensor
    const auto pa = a.get();
    // Obtiene el valor del segundo tensor
    const auto pb = b.get();
    // Creacion del tensor vacio
    Tensor<type> tensor(ranks, cols, rows);
    const auto result = tensor.data.get();
    // Calculo de la suma
    for (int n = 0; n < ranks * cols * rows; n++)
    {
        result[n] = pa[n] + pb[n];
    }
    return tensor;
}

template <typename type>
Tensor<type> Tensor<type>::diff(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
{
    // Obtiene el valor del primer tensor
    const auto pa = a.get();
    // Obtiene el valor del segundo tensor
    const auto pb = b.get();
    // Creacion del tensor vacio
    Tensor<type> tensor(ranks, cols, rows);
    const auto result = tensor.data.get();
    // Calculo de la resta
    for (size_t n = 0; n < ranks * cols * rows; n++)
    {
        result[n] = pa[n] - pb[n];
    }
    return tensor;
}

template <typename type>
Tensor<type> Tensor<type>::mult(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
{
    // Obtiene el valor del primer tensor
    const auto pa = a.get();
    // Obtiene el valor del segundo tensor
    const auto pb = b.get();
    // Creacion del tensor vacio
    Tensor<type> tensor(ranks, cols, rows);
    const auto result = tensor.data.get();
    // Calculo de la multiplicacion
    for (size_t n = 0; n < ranks * cols * rows; n++)
    {
        result[n] = pa[n] * pb[n];
    }
    return tensor;
}

template <typename type>
Tensor<type> Tensor<type>::div(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
/* D */
{
    // Obtiene el valor del primer tensor
    const auto pa = a.get();
    // Obtiene el valor del segundo tensor
    const auto pb = b.get();
    // Creacion del tensor vacio
    Tensor<type> tensor(ranks, cols, rows);
    const auto result = tensor.data.get();
    // Calculo de la division
    for (size_t n = 0; n < ranks * cols * rows; n++)
    {
        result[n] = pa[n] / pb[n];
    }
    return tensor;
}
template <typename type>
Tensor<type>::Tensor()
{
    // Creacion del tensor vacio
    ranks = cols = rows = 0;
}
template <typename type>
Tensor<type>::Tensor(
    size_t cols_input,
    size_t rows_input)
{
    ranks = 1;
    cols = cols_input;
    rows = rows_input;
    data = std::shared_ptr<type[]>(new type[ranks * rows * cols]);
}
template <typename type>
Tensor<type>::Tensor(
    size_t ranks_input,
    size_t cols_input,
    size_t rows_input)
{
    ranks = ranks_input;
    cols = cols_input;
    rows = rows_input;
    data = std::shared_ptr<type[]>(new type[cols * rows * ranks]);
}
template <typename type>
Tensor<type>::Tensor(type *data_input,
                     size_t ranks_input,
                     size_t cols_input,
                     size_t rows_input)
{
    ranks = ranks_input;
    cols = cols_input;
    rows = rows_input;
    data = std::shared_ptr<type[]>(data_input);
}
template <typename type>
Tensor<type>::Tensor(
    const Tensor &copy)
{
    ranks = copy.ranks;
    cols = copy.cols;
    rows = copy.rows;
    data = std::shared_ptr<type[]>(new type[cols * rows * ranks]);
    // Copia de los valores, el cambio en un tensor no afecta al otro
    for (size_t i = 0; i < cols * rows * ranks; i++)
    {
        data[i] = copy.data[i];
    }
}
template <typename type>
Tensor<type>::~Tensor()
{
}
template <typename type>
size_t Tensor<type>::get_ranks()
{
    return ranks;
}
template <typename type>
size_t Tensor<type>::get_cols()
{
    return cols;
}
template <typename type>
size_t Tensor<type>::get_rows()
{
    return rows;
}
template <typename type>
void Tensor<type>::print()
{
    for (size_t i = 0; i < ranks; i++)
    {
        std::cout << "Capa " << i + 1 << std::endl;
        for (size_t j = 0; j < rows; j++)
        {
            for (size_t k = 0; k < cols; k++)
            {
                std::cout << data[i * (rows * cols) + j * cols + k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
#endif
