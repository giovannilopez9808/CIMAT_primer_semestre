int reverse_number(int number)
{
    /* 
    Regresa el numero escrito al reves
     */
    // Inicializacion del numerp
    int reverse = 0;
    // Variable auxiliar
    int aux;
    while (number != 0)
    {
        // Obtiene el primer digito del numero
        aux = number % 10;
        // Suma el primer digito del numero y los anteriores les multiplica por 10
        reverse = reverse * 10 + aux;
        // Eliminacion del primer digito
        number /= 10;
    }
    return reverse;
}