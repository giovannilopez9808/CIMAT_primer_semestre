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
    ~Tensor();
};
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
{}
#endif
