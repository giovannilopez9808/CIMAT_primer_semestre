#ifndef tensor_H
#define tensor_H
#include <memory>
template <typename type>
class Tensor
{
private:
    std::shared_ptr<type> m_data;
    size_t m_ranks;
    size_t m_cols;
    size_t m_rows;

    Tensor<type> *sum(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);
    Tensor<type> *diff(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);
    Tensor<type> *mult(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);
    Tensor<type> *div(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b);

public:
    Tensor();
    Tensor(type *data,
           size_t ranks,
           size_t cols,
           size_t rows);
    Tensor(size_t ranks,
           size_t cols,
           size_t rows);
    Tensor(size_t cols,
           size_t rows);
    Tensor(const Tensor &copy);
    Tensor<type> *operator+(const Tensor<type> &operand);
    Tensor<type> *operator*(const Tensor<type> &operand);
    Tensor<type> *operator-(const Tensor<type> &operand);
    Tensor<type> *operator/(const Tensor<type> &operand);
    size_t get_ranks();
    size_t get_cols();
    size_t get_rows();
    type *get_data();
    ~Tensor();
};

template <typename type>
Tensor<type> *Tensor<type>::operator+(const Tensor<type> &operand)
{
    return sum(m_data, operand.m_data);
}
template <typename type>
Tensor<type> *Tensor<type>::operator*(const Tensor<type> &operand)
{
    return mult(m_data, operand.m_data);
}
template <typename type>
Tensor<type> *Tensor<type>::operator-(const Tensor<type> &operand)
{
    return diff(m_data, operand.m_data);
}
template <typename type>
Tensor<type> *Tensor<type>::operator/(const Tensor<type> &operand)
{
    return div(m_data, operand.m_data);
}
template <typename type>
type *Tensor<type>::get_data()
{
    return m_data.get();
}
template <typename type>
Tensor<type> *Tensor<type>::sum(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
{
    const auto pa = a.get();
    const auto pb = b.get();
    Tensor<type> tensor(m_ranks, m_cols, m_rows);
    const auto result = tensor.m_data.get();
    for (int n = 0; n < m_ranks * m_cols * m_rows; n++)
    {
        result[n] = pa[n] + pb[n];
    }
    return tensor;
}
template <typename type>
Tensor<type> *Tensor<type>::diff(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
{
    const auto pa = a.get();
    const auto pb = b.get();
    Tensor<type> tensor(m_ranks, m_cols, m_rows);
    const auto result = tensor.m_data.get();
    for (int n = 0; n < m_ranks * m_cols * m_rows; n++)
    {
        result[n] = pa[n] - pb[n];
    }
    return tensor;
}

template <typename type>
Tensor<type> *Tensor<type>::mult(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
{
    const auto pa = a.get();
    const auto pb = b.get();
    Tensor<type> tensor(m_ranks, m_cols, m_rows);
    const auto result = tensor.m_data.get();
    for (int n = 0; n < m_ranks * m_cols * m_rows; n++)
    {
        result[n] = pa[n] * pb[n];
    }
    return tensor;
}

template <typename type>
Tensor<type> *Tensor<type>::div(std::shared_ptr<type[]> a, std::shared_ptr<type[]> b)
{
    const auto pa = a.get();
    const auto pb = b.get();
    Tensor<type> tensor(m_ranks, m_cols, m_rows);
    const auto result = tensor.m_data.get();
    for (int n = 0; n < m_ranks * m_cols * m_rows; n++)
    {
        result[n] = pa[n] / pb[n];
    }
    return tensor;
}
template <typename type>
Tensor<type>::Tensor()
{
    m_ranks = m_cols = m_rows = 0;
}
template <typename type>
Tensor<type>::Tensor(
    size_t cols,
    size_t rows)
{
    m_ranks = 1;
    m_cols = cols;
    m_rows = rows;
    m_data = std::make_shared<type>(new Tensor[m_ranks * m_rows * m_cols]);
}
template <typename type>
Tensor<type>::Tensor(
    size_t ranks,
    size_t cols,
    size_t rows)
{
    m_ranks = ranks;
    m_cols = cols;
    m_rows = rows;
    m_data = std::make_shared<type>(new Tensor[m_ranks * m_rows * m_cols]);
}
template <typename type>
Tensor<type>::Tensor(type *data,
                     size_t ranks,
                     size_t cols,
                     size_t rows)
{
    m_ranks = ranks;
    m_cols = cols;
    m_rows = rows;
    m_data = std::make_shared<type>(*data);
}
template <typename type>
Tensor<type>::Tensor(
    const Tensor &copy)
{
    m_ranks = copy.m_ranks;
    m_cols = copy.m_cols;
    m_rows = copy.m_rows;
    m_data = copy.m_data;
}
template <typename type>
Tensor<type>::~Tensor()
{
}
template <typename type>
size_t Tensor<type>::get_ranks()
{
    return m_ranks;
}
template <typename type>
size_t Tensor<type>::get_cols()
{
    return m_cols;
}
template <typename type>
size_t Tensor<type>::get_rows()
{
    return m_rows;
}
#endif
