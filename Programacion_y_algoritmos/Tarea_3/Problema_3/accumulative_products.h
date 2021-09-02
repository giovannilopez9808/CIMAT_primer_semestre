void products(int numbers[], long int product[], int size)
{
    int i;
    long int all_product = 1;
    // Realiza el producto de todos lo numeros en la lista
    for (i = 0; i < size; i++)
    {
        all_product *= numbers[i];
    }
    // Divide el elemento i de los numeros con el producto de todos
    for (i = 0; i < size; i++)
    {
        product[i] = all_product / numbers[i];
    }
}
