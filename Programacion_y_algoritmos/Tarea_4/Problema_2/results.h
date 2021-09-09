void write_sample_space(int data[number_letters][number_letters])
{
    /* 
    Escritura del espacio muestral de los resultados
     */
    FILE *results;
    results = fopen("sample_space.csv", "w");
    // Header del archivo
    for (int i = 0; i < number_letters; i++)
    {
        fprintf(results, ",%c", i + begin_letter_cap);
    }
    fprintf(results, "\n");
    for (int i = 0; i < number_letters; i++)
    {
        // Index del archivo
        fprintf(results, "%c", i + begin_letter_cap);
        for (int j = 0; j < number_letters; j++)
        {
            // Resultados
            fprintf(results, ",%d", data[i][j]);
        }
        fprintf(results, "\n");
    }
    fclose(results);
}
void write_probabilities(int probabilities[number_letters], int total)
{
    /* 
    Escritura del espacio muestral de los resultados
     */
    FILE *results;
    results = fopen("probabilities.csv", "w");
    // Header del archivo
    fprintf(results, "Probabilities,Value\n");
    for (int i = 0; i < number_letters; i++)
    {
        // Index del archivo
        fprintf(results, "%c,", obtain_capital_letter(i));
        fprintf(results, "%lf\n", probabilities[i] * 100.0 / total);
    }
    fclose(results);
}
void write_conditional_probabilities(int probabilities[number_letters], int positions[number_letters], int data[number_letters][number_letters])
{
    /* 
    Imprime las probabilidades condicionales de las 10 letras que mas se repiten
     */
    char letter_i,
        letter_j;
    //  Recorrido para las 10 letras
    for (int i = 0; i < 10; i++)
    {
        // Caracter de la i letra
        letter_i = obtain_capital_letter(positions[i]);
        // Impresion del header
        printf("P(%c|A,...,Z)\n", letter_i);
        // Recorrido para todas sus probabilidades condicionales
        for (int j = 0; j < number_letters; j++)
        {
            // Caracter de la j letra
            letter_j = obtain_capital_letter(j);
            // Impresion
            printf("\tP(%c|%c) = %lf %%\n",
                   letter_i,
                   letter_j,
                   data[positions[i]][j] * 100.0 / probabilities[i]);
        }
        print_lines();
    }
}
void initialize_data(int data[number_letters][number_letters], int probabilities[number_letters], int positions[number_letters])
{
    /* 
    Inicializacion de la variable
     */
    for (int i = 0; i < number_letters; i++)
    {
        probabilities[i] = 0;
        positions[i] = i;
        for (int j = 0; j < number_letters + 1; j++)
        {
            data[i][j] = 0;
        }
    }
}
void print_probabilities(int probabilities[number_letters], int positions[number_letters], int total)
{
    /* 
    Imprime todas las probabilidades de las letras
     */
    print_lines();
    printf("Probabilidades de cada letra\n");
    for (int i = 0; i < number_letters; i++)
    {
        printf("P(%c) = %2.6lf %% \n",
               obtain_capital_letter(positions[i]),
               probabilities[i] * 100.0 / total);
    }
    print_lines();
}