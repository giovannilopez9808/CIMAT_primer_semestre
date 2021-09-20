void obtain_subraction_matrix(double *matrix_b, double *matrix_rx, double *matrix_res, int dimesion_matrix[])
{
    /* 
    Realiza la resta de matrices
     */
    double *R_i, *Rx_i, *Res_i;
    for (int i = 0; i < dimesion_matrix[0]; i++)
    {
        Rx_i = (matrix_rx + i);
        R_i = (matrix_b + i);
        Res_i = (matrix_res + i);
        *Res_i = *R_i - *Rx_i;
    }
}
void obtain_multiplication_matrix(double *A, double *B, double *AB, int dimension_matrix_A[], int dimension_matrix_B[])
{
    /* 
    Realiza la multiplicacion de matrices
     */
    double a_ik, b_kj, *AB_ij;
    double sum;
    for (int i = 0; i < dimension_matrix_A[0]; i++)
    {
        for (int j = 0; j < dimension_matrix_B[1]; j++)
        {
            sum = 0;
            AB_ij = (AB + j * dimension_matrix_B[0] + i);
            for (int k = 0; k < dimension_matrix_B[0]; k++)
            {
                a_ik = *(A + k * dimension_matrix_A[0] + i);
                b_kj = *(B + j * dimension_matrix_B[0] + k);
                sum += a_ik * b_kj;
            }
            *AB_ij = sum;
        }
    }
}