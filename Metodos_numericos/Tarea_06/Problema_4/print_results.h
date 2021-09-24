void print_solution(double *solution, int dimension_matrix[])
{
    /* 
    Realiza la impresion de la solucion del sistema de ecuaciones
     */
    print_lines();
    printf("Soluciones del sistema\n\n");
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        printf("x_%d\t= %lf\n",
               i + 1,
               *(solution + i));
    }
}