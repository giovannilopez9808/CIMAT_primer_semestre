void print_person_per_group(int persons[6])
{
    printf("Grupo\tPersonas\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%c\t%d\n", 'A' + i, persons[i]);
    }
}
void print_person_per_turn(int persons[2])
{
    printf("Turno\t\tPersonas\n");
    printf("Matutino\t%d\n", persons[0]);
    printf("Vespertino\t%d\n", persons[1]);
}