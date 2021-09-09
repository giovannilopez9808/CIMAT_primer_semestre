void count_data(int letter1, int letter2, int data[number_letters][number_letters])
{
    /* 
    Realiza el conteo y lo ubica en la matriz de 26x27, esto para despues calcular la probabilidad condicional
     */
    int position1 = equal_capital_and_lower_letters(letter1);
    int position2 = equal_capital_and_lower_letters(letter2);
    data[position2][position1] = data[position2][position1] + 1;
}
void count_individual_data(int letter, int probabilities[number_letters])
{
    /* 
    Realiza el conteo de individual de cada letra
     */
    int position = equal_capital_and_lower_letters(letter);
    probabilities[position] = probabilities[position] + 1;
}
void valid_second_letter(FILE *text_file, char *letter1, char *letter2, int probabilities[number_letters])
{
    /* 
    Valida que el segundo caracter sea una letra
     */
    // Variable auxiliar usada para evitar warmings
    char letter_aux = *letter1;
    (void)letter_aux;
    // Validacion si es una letra
    if (!is_a_letter(*letter2))
    {
        // Si no lo es, entonces se puede tratar de un punto, coma o espacio
        if (!is_a_space(*letter2))
        {
            // Si no es un espacio entonces es un punto o coma, entonces se lo salta
            *letter2 = fgetc(text_file);
        }
        // Si es un espacio, entonces lo siguiente es una letra
        *letter1 = fgetc(text_file);
        // Contador de la ultima letra antes de un espacio, coma o punto.
        count_individual_data((int)*letter1, probabilities);
        *letter2 = fgetc(text_file);
    }
}
void obtain_data(FILE *text_file, int data[number_letters][number_letters], int probabilities[number_letters])
{
    char letter1,
        letter2;
    letter1 = fgetc(text_file);
    letter2 = fgetc(text_file);
    // Conteo de la primer letra
    while (letter1 != EOF && letter2 != EOF)
    {
        // Validacion de la segunda letra
        valid_second_letter(text_file, &letter1, &letter2, probabilities);
        // Conteo de las probabilidades condicionales
        count_data(letter1, letter2, data);
        // Intercambio de las letras
        letter1 = letter2;
        count_individual_data(letter1, probabilities);
        letter2 = fgetc(text_file);
        // Conteo de la probabilidad de cada letra
        // Validacion por si se encuentra cerca del final del archivo
        valid_second_letter(text_file, &letter1, &letter2, probabilities);
    }
    fclose(text_file);
}
void obtain_total_letters(int *total, int probabilities[number_letters])
{
    for (int i = 0; i < number_letters; i++)
    {
        *total = *total + probabilities[i];
    }
}
void print_lines()
{
    printf("-------------");
    printf("-------------\n");
}
