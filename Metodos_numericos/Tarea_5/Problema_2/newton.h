double obtain_new_x_newton(double (*f)(double), double x)
{
    /* 
    Calculo del nuevo posible valor de la raiz siguiendo el algoritmo de newton
     */
    double df = derivate(f, x);
    double ddf = double_derivate(f, x);
    // Variable auxiliar
    double aux = df / ddf;
    x = x - aux;
    return x;
}
void newton_method(double (*f)(double), double x0)
{
    /* 
    Metodo de Newton para obtener la raiz de una funcion.
    (*f) -> funcion que recibe un dato double y devuelve un double
    x0 -> Valor aproximado de la raiz
     */
    printf("\tNewton:\n");
    double df = 1;
    // Inicializacion de la variable de busqueda
    double x = x0 + 1;
    // Tolerancia
    double tau = 1e-12;
    // Inicializacion del numero de intentos
    int attempt = 0;
    printf("\t\tInteraciones\tAproximación\tTolerancia\n");
    while (fabs(derivate(f, x)) > tau)
    {
        x0 = x;
        // Calculo de la derivada en x
        df = derivate(f, x);
        // Si la derivada es cercana a 0 el algoritmo se detiene
        if (fabs(df) < tau)
        {
            break;
        }
        x = obtain_new_x_newton(f, x);
        attempt++;
        printf("\t\t\t%d\t%.12lf\t%.12lf\n", attempt, x, fabs(derivate(f, x)));
    }
    // Impresion de salida si la derivada es cercana a 0
    if (fabs(df) < tau)
    {
        printf("\t\tAlgoritmo terminado por\n\t\tobtener una derivada cercana a 0 (%lf)\n", df);
    }
    // Impresion del resultado, si es que lo hubo
    if ((fabs(df) > tau))
    {
        printf("\t\tSolucion: x = %.12lf\n", x);
    }
}