int is_the_word(FILE *text, char *letter, char word[])
{
    /* 
    Reconoce si el texto siguiente del texto es la letra que se busca
     */
    int diff_char = 0, i = 1, letter1, letter2;
    while (diff_char == 0 && word[i] != '\0')
    {
        *letter = fgetc(text);
        // Transformación a todas minusculas
        letter1 = equal_capital_and_lower_letters(word[i]);
        letter2 = equal_capital_and_lower_letters(*letter);
        diff_char = letter1 - letter2;
        i += 1;
    }
    // Si se llego al final de la palabra buscada y la ultima letra del texto coincide con la ultima letra de la palabra
    if (word[i] == '\0' && *letter == word[i - 1])
    {
        // Si el siguiente caracter del texto no es una letra, entonces se considera que se encontro la palabra
        *letter = fgetc(text);
        if (!is_a_letter(*letter))
        {

            return 1;
        }
    }
    return 0;
}
int find_word(FILE *text, char word[])
{
    /*
    Encuentra una palabra en un texto e imprime cuantas veces se encontro
     */
    char letter, letter_behind = ' ';
    int diff_char, letter_text, letter_word, count = 0;
    // Se lee el primer caracter del texto
    letter = fgetc(text);
    // Transformacion a minusculas del primer caracter de la palabra buscada
    letter_word = equal_capital_and_lower_letters(word[0]);
    while (letter != EOF)
    {
        // Transformacion a minusculas del primer caracter del texto
        letter_text = equal_capital_and_lower_letters(letter);
        diff_char = letter_word - letter_text;
        // Si coincide la letra
        if (diff_char == 0)
        {
            // Si la letra anterior no es una letra
            if (!is_a_letter(letter_behind))
            {
                // Si todos los caracteres coinciden
                if (is_the_word(text, &letter, word))
                {
                    // Se encontro la palabra
                    count++;
                }
            }
        }
        letter_behind = letter;
        letter = fgetc(text);
    }
    return count;
}