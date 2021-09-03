void obtain_new_x_secant(double (*f)(double), double *x0, double *x1)
{
    /* 
    Calculo de la posible raiz de la funcion
     */
    // Variable auxiliar para guardar el valor de x1
    double df0 = derivate(f, *x0);
    double df1 = derivate(f, *x1);
    // Variables auxiliares para el calculo de el valor critico
    double up = df1 * (*x1 - *x0);
    double down = df1 - df0;
    double aux = *x1 - up / down;
    *x0 = *x1;
    *x1 = aux;
}
void secant_method(double (*f)(double), double x1, double x0)
{
    /* 
    Metodo de secante para obtener la raiz de una funcion en un intervalo dado.
    (*f) -> funcion que recibe un dato double y devuelve un double
        x0 -> limite inferior del intervalo
        x1 -> limite superior del intervalo
    */
    double tau = 1e-6;
    double df = derivate(f, x0);
    printf("\tSecante:\n");
    while (fabs(df) > tau)
    {
        obtain_new_x_secant(f, &x0, &x1);
        df = derivate(f, x0);
    }
    printf("\t\tx = %lf\n", x1);
}