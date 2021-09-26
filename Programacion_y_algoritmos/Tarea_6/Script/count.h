void count_per_group(struct student *students, int size, int count[6])
{
    int letter;
    for (int i = 0; i < 6; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        letter = students[i].s.group - 'A';
        count[letter] += 1;
    }
}
void count_per_turn(struct student *students, int size, int count[2])
{
    for (int i = 0; i < 2; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (students[i].s.turn == 'M')
        {
            count[0] += 1;
        }
        else
        {
            count[1] += 1;
        }
    }
}