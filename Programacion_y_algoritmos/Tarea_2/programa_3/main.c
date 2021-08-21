#include <stdio.h>
#include "functions.h"
void select_operation(int fraction1[], int fraction2[], char sign, int result[])
{
    /* 
    Realiza la operacion indicada en el caracter sign.
    Inputs:
    + fraction1: Fraccion 1 que realizara la operacion
    + fraction2: Fraccion 2 que realizara la operacion
    + sign: caracter con la operacion +, -, * o /
    + result: fraccion del resultado
     */
    switch (sign)
    {
    case '+':
        /* 
    Realiza la operacion de suma
     */
        obtain_fraction_sum(fraction1,
                            fraction2,
                            result);
        break;
    case '-':
        /* 
    Realiza la operacion de resta
     */
        obtain_fraction_subtraction(fraction1,
                                    fraction2,
                                    result);
        break;
    case '*':
        /* 
    Realiza la operacion de multiplicacion
     */
        obtain_fraction_multiplication(fraction1,
                                       fraction2,
                                       result);
        break;
    case '/':
        /* 
    Realiza la operacion de division
     */
        obtain_fraction_division(fraction1,
                                 fraction2,
                                 result);
        break;
    default:
        /* 
    Seccion para las operaciones no definidas
     */
        print_lines();
        printf("Operación invalida\n");
        print_lines();
        result[0] = 0;
        result[1] = 0;
        break;
    }
}
void print_result(int fraction1[], int fraction2[], int result[], char sign)
{
    /* 
    Imprime en pantalla el resultado de la operacion
     */
    print_lines();
    printf("El resultado es\n%d/%d %c %d/%d = %d/%d\n",
           fraction1[0],
           fraction1[1],
           sign,
           fraction2[0],
           fraction2[1],
           result[0],
           result[1]);
    print_lines();
}
int main()
{
    // Inicializacion de las variables
    int fraction1[2];
    int fraction2[2];
    char sign;
    int result[2];
    // Lectura de la primer fraccion
    read_operation(fraction1,
                   fraction2,
                   &sign);
    select_operation(fraction1,
                     fraction2,
                     sign,
                     result);
    // Impresion delos resultados
    print_result(fraction1,
                 fraction2,
                 result,
                 sign);
    return 0;
}