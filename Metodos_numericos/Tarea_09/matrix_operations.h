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
void normalize_vector(double *vector, int dimension[])
{
    double max = *vector;
    double v_i, *V_i;
    for (int i = 1; i < dimension[0]; i++)
    {
        v_i = fabs(*(vector + i));
        if (max < v_i)
        {
            max = v_i;
        }
    }
    for (int i = 0; i < dimension[0]; i++)
    {
        v_i = *(vector + i);
        V_i = (vector + i);
        *V_i = v_i / max;
    }
}