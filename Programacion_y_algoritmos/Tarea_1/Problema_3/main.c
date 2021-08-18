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

int obtain_lowest_common_multiple(int number1, int number2)
{
    /* 
    Obtiene el minimo comun multiplo dados dos numeros enteros
     */
    return (number1 * number2) / obtain_greatest_common_divisor(number1,
                                                                number2);
}

void print_init_program()
{
    /* 
    Imprime en pantalla el proposito del programa
     */
    printf("Programa que suma dos fracciones\n a/b + c/d\n");
}

void print_result(int fraction1[], int fraction2[], int result[])
{
    /* 
    Imprime en pantalla el resultado de la operacion
     */
    printf("El resultado es\n%d/%d + %d/%d = %d/%d\n",
           fraction1[0],
           fraction1[1],
           fraction2[0],
           fraction2[1],
           result[0],
           result[1]);
}

void read_number(int fraction[], char *letter1, char *letter2)
{
    /* 
    Lectura de las fracciones en el formato a/b, donde a y b son enteros
     */
    printf("Introducir %s/%s\n",
           letter1,
           letter2);
    scanf("%d/%d",
          &fraction[0],
          &fraction[1]);
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
int main()
{
    // Inicializacion de las variables
    int fraction1[2];
    int fraction2[2];
    int result[2];
    // Impresion en pantalla del inicio del programa
    print_init_program();
    // Lectura de la primer fraccion
    read_number(fraction1,
                "a",
                "b");
    // Lectura de la segunda fraccion
    read_number(fraction2,
                "c",
                "d");
    // Suma de fracciones
    obtain_fraction_sum(fraction1,
                        fraction2,
                        result);
    // Impresion delos resultados
    print_result(fraction1,
                 fraction2,
                 result);
    return 0;
}