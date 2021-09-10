struct person
{
    char last_name_1[20];
    char last_name_2[20];
    char name[40];
};
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
