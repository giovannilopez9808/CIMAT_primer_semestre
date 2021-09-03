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
    double tau = 1e-6;
    // Inicializacion del numero de intentos
    int attempt = 0;
    // Maximo de intentos
    int max_attempt = log2(fabs(x0) / tau);
    while (fabs(derivate(f, x)) > tau && attempt < max_attempt)
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
    }
    // Impresion de salida si la derivada es cercana a 0
    if (fabs(df) < tau)
    {
        printf("\t\tAlgoritmo terminado por\n\t\tobtener una derivada cercana a 0 (%lf)\n", df);
    }
    // Impresion de salida si se llego al maximo de intentos
    if (attempt >= max_attempt)
    {
        printf("\t\tAlgoritmo terminado por\n\t\tmaximo de intentos (%d)\n", max_attempt);
    }
    // Impresion del resultado, si es que lo hubo
    if ((attempt < max_attempt) && (fabs(df) > tau))
    {
        printf("\t\tx = %lf\n", x);
    }
}