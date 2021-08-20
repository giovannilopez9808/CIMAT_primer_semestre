#include <stdio.h>
void print_lines()
{
    printf("------------------\n");
}
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

int obtain_lowest_common_multiple(int number1, int number2)
{
    /* 
    Obtiene el minimo comun multiplo dados dos numeros enteros
     */
    return (number1 * number2) / obtain_greatest_common_divisor(number1,
                                                                number2);
}
void read_operation(int fraction1[], int fraction2[], char *sign)
{
    /* 
    Lectura de las fracciones en el formato a/b, donde a y b son enteros
     */
    print_lines();
    printf("Introdduce la operacion que quieres realizar de la forma\n\na/b&c/d\n\n& puede ser +, -, *, / \n");
    print_lines();
    scanf("%d/%d%c%d/%d",
          &fraction1[0],
          &fraction1[1],
          sign,
          &fraction2[0],
          &fraction2[1]);
}
void obtain_aux_fraction(int fraction[], int minimum_comun)
{
    /* 
    Obtiene la fraccion auxiliar para realizar la suma de fracciones con el divisor igual al minimo comun multiplo de las dos fracciones
     */
    int aux = minimum_comun / fraction[1];
    // Calculo de la fraccion auxiliar
    fraction[0] = fraction[0] * aux;
    fraction[1] = minimum_comun;
}
void obtain_fraction_sum(int fraction1[], int fraction2[], int result[])
{
    /* 
    Realiza la suma de las dos fracciones obtiendo el minimo comun multiplo de los divisores
     */
    // Calculo del minimo comun multiplo de los divisores
    result[1] = obtain_lowest_common_multiple(fraction1[1],
                                              fraction2[1]);
    // Calculo de la primer fraccion auxiliar
    obtain_aux_fraction(fraction1,
                        result[1]);
    // Calculo de la segunda fraccion auxiliar
    obtain_aux_fraction(fraction2,
                        result[1]);
    // Suma de los dividendos de las fracciones auxiliares
    result[0] = fraction1[0] + fraction2[0];
}
void obtain_fraction_subtraction(int fraction1[], int fraction2[], int result[])
{
    /* 
    Realiza la suma de las dos fracciones obtiendo el minimo comun multiplo de los divisores
     */
    // Calculo del minimo comun multiplo de los divisores
    result[1] = obtain_lowest_common_multiple(fraction1[1],
                                              fraction2[1]);
    // Calculo de la primer fraccion auxiliar
    obtain_aux_fraction(fraction1,
                        result[1]);
    // Calculo de la segunda fraccion auxiliar
    obtain_aux_fraction(fraction2,
                        result[1]);
    // Suma de los dividendos de las fracciones auxiliares
    result[0] = fraction1[0] - fraction2[0];
}
void obtain_fraction_multiplication(int fraction1[], int fraction2[], int result[])
{
    /* 
    Realiza la suma de las dos fracciones obtiendo el minimo comun multiplo de los divisores
     */
    result[0] = fraction1[0] * fraction2[0];
    result[1] = fraction1[1] * fraction2[1];
}
void obtain_fraction_division(int fraction1[], int fraction2[], int result[])
{
    /* 
    Realiza la suma de las dos fracciones obtiendo el minimo comun multiplo de los divisores
     */
    result[0] = fraction1[0] * fraction2[1];
    result[1] = fraction1[1] * fraction2[0];
}
