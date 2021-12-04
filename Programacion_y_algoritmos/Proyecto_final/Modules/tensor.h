#ifndef tensor_H
#define tensor_H
#include <iostream>
#include <memory>
template <typename type>
class Tensor
{
private:
    std::shared_ptr<type[]> data;
    size_t ranks;
    size_t cols;
    size_t rows;

    Tensor<type> sum(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);
    Tensor<type> diff(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);
    Tensor<type> mult(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);
    Tensor<type> div(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);

public:
    Tensor();
    Tensor(type *data_input,
           size_t ranks_input,
           size_t cols_input,
           size_t rows_input);
    Tensor(size_t ranks_input,
           size_t cols_input,
           size_t rows_input);
    Tensor(size_t cols_input,
           size_t row_inputs);
    Tensor(const Tensor &copy);
    Tensor<type> operator+(const Tensor<type> &operand);
    Tensor<type> operator*(const Tensor<type> &operand);
    Tensor<type> operator-(const Tensor<type> &operand);
    Tensor<type> operator/(const Tensor<type> &operand);
    size_t get_ranks();
    size_t get_cols();
    size_t get_rows();
    type *get_data();
    void print();
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
    const auto pa = a.get();
    const auto pb = b.get();
    // std::cout << ranks << rows << cols << std::endl;
    Tensor<type> tensor(ranks, cols, rows);
    const auto result = tensor.data.get();
    for (int n = 0; n < ranks * cols * rows; n++)
    {
        result[n] = pa[n] + pb[n];
    }
    return tensor;
}
template <typename type>
Tensor<type> Tensor<type>::diff(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
{
    const auto pa = a.get();
    const auto pb = b.get();
    Tensor<type> tensor(ranks, cols, rows);
    const auto result = tensor.data.get();
    for (size_t n = 0; n < ranks * cols * rows; n++)
    {
        result[n] = pa[n] - pb[n];
    }
    return tensor;
}

template <typename type>
Tensor<type> Tensor<type>::mult(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
{
    const auto pa = a.get();
    const auto pb = b.get();
    Tensor<type> tensor(ranks, cols, rows);
    const auto result = tensor.data.get();
    for (size_t n = 0; n < ranks * cols * rows; n++)
    {
        result[n] = pa[n] * pb[n];
    }
    return tensor;
}

template <typename type>
Tensor<type> Tensor<type>::div(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
{
    const auto pa = a.get();
    const auto pb = b.get();
    Tensor<type> tensor(ranks, cols, rows);
    const auto result = tensor.data.get();
    for (size_t n = 0; n < ranks * cols * rows; n++)
    {
        result[n] = pa[n] / pb[n];
    }
    return tensor;
}
template <typename type>
Tensor<type>::Tensor()
{
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
