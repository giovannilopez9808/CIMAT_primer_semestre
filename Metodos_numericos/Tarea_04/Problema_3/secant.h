void obtain_new_x_secant(double (*f)(double), double *x0, double *x1)
{
    /* 
    Calculo de la posible raiz de la funcion
     */
    // Variable auxiliar para guardar el valor de x1
    double aux = *x1;
    double fx0 = f(*x0);
    double fx1 = f(*x1);
    // Variables auxiliares para el calculo de la nueva raiz
    double up = *x0 * fx1 - *x1 * fx0;
    double down = fx1 - fx0;
    *x1 = up / down;
    *x0 = aux;
}
void secant_method(double (*f)(double), double x0, double x1)
{
    /* 
    Metodo de secante para obtener la raiz de una funcion en un intervalo dado.
    (*f) -> funcion que recibe un dato double y devuelve un double
        x0 -> limite inferior del intervalo
        x1 -> limite superior del intervalo
    */
    double tau = 1e-6;
    printf("\tSecante:\n");
    while (stopping_criteria(x0, x1) > tau)
    {
        obtain_new_x_secant(f, &x0, &x1);
    }
    printf("\t\tx = %lf\n", x1);
}