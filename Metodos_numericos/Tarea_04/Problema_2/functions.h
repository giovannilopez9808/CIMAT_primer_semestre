#include <math.h>
double stopping_criteria(double x0, double x1)
{
    /* 
    Criterio para pararel algoritmo por diferencia relativa o diferencia absoluta
     */
    double diff = fabs(x1 - x0);
    double max_value = fmax(1.0, fabs(x1));
    return diff / max_value;
}