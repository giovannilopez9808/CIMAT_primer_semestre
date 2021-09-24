void print_lines()
{
    printf("----------------------");
    printf("----------------------\n");
}
void valid_solution(double number)
{
    /* 
    Realiza la validacion del sistema de ecuaciones lineales
     */
    if (number == 0)
    {
        print_lines();
        printf("Sistema sin solución\n");
        exit(1);
    }
}