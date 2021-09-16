void print_lines()
{
    printf("\n---------------------------------");
    printf("---------------------------------\n");
}
void print_token_i(char **tokens, int location)
{
    printf("%d\t\t%s\n", location, *tokens + location * size_per_word);
}
void print_tokens(char **tokens, int size)
{
    printf("Posicion\tValor\n");
    for (int i = 0; i < size; i++)
    {
        print_token_i(tokens, i);
    }
}