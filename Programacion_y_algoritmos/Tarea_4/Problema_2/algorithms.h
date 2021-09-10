void obtain_conditional_probability(int letter1, int letter2, int data[number_letters][number_letters])
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
    (void)probabilities;
    // Validacion si es una letra
    while (!is_a_letter(*letter2) && (*letter2 != EOF || *letter1 != EOF))
    {
        *letter1 = fgetc(text_file);
        while (!is_a_letter(*letter1) && *letter1 != EOF)
        {
            *letter1 = fgetc(text_file);
        }
        *letter2 = fgetc(text_file);
        if (is_a_space(*letter2))
        {
            count_individual_data(*letter1,
                                  probabilities);
        }
    }
}
void obtain_data(FILE *text_file, int data[number_letters][number_letters], int probabilities[number_letters])
{
    char letter1, letter2;
    letter1 = fgetc(text_file);
    letter2 = fgetc(text_file);
    // Conteo de la primer letra
    while (letter1 != EOF && letter2 != EOF)
    {
        // Validacion de la segunda letra
        valid_second_letter(text_file,
                            &letter1,
                            &letter2,
                            probabilities);
        if (letter1 != EOF && letter2 != EOF)
        {
            // Conteo de las probabilidades condicionales
            obtain_conditional_probability(letter1,
                                           letter2,
                                           data);
            // Intercambio de las letras
            letter1 = letter2;
            letter2 = fgetc(text_file);
            count_individual_data(letter1,
                                  probabilities);
        }
    }
    if (letter2 != EOF)
    {
        count_individual_data(letter2,
                              probabilities);
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
