#include <stdio.h>
int obtain_greatest_common_divisor(int number1, int number2)
{
    /* 
    Obtiene el maximo comun divisor dados dos numeros enteros
    */
    int aux;
    while (number2 != 0)
    {
        aux = number2;
        number2 = number1 % number2;
        number1 = aux;
    }
    return number1;
}
void reduce_number(int fraction[])
{
    int GCD = obtain_greatest_common_divisor(fraction[0],
                                             fraction[1]);
    fraction[0] = fraction[0] / GCD;
    fraction[1] = fraction[1] / GCD;
}
void read_number(int fraction[])
{
    /* 
    Lectura de las fracciones en el formato a/b, donde a y b son enteros
     */
    printf("Introduce la fraccion con el formato a/b: ");
    scanf("%d/%d",
          &fraction[0],
          &fraction[1]);
}
void print_result(int fraction[])
{
    printf("La fraccion reducida es: %d/%d\n",
           fraction[0],
           fraction[1]);
}
int main()
{
    int fraction[2];
    read_number(fraction);
    reduce_number(fraction);
    print_result(fraction);
}