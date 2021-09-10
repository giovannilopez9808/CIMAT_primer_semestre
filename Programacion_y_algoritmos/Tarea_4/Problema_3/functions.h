struct person
{
    char last_name_1[20];
    char last_name_2[20];
    char name[40];
};
int order_names(char name1[], char name2[])
{
    int i = 0;
    int compare;
    while (name1[i] != '\0' && name2[i] != '\0')
    {
        compare = name1[i] - name2[i];
        if (compare != 0)
        {
            return compare;
        }
        i++;
    }
    return 0;
}

void print_names(struct person **pointers, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s %s %s\n",
               pointers[i]->last_name_1,
               pointers[i]->last_name_2,
               pointers[i]->name);
    }
}
