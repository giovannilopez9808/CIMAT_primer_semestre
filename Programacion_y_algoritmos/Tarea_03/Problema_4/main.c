#include "quick_sort.h"
#include "merge.h"
#include "test_data.h"
#include "custom_data.h"
void decide_case()
{
    char test;
    printf("¿Deseas usar el programa con los datos de prueba?(Y/n): ");
    scanf("%c", &test);
    if (test == 'Y' || test == 'y')
    {
        test_data();
    }
    else
    {
        custom_data();
    }
}
int main()
{
    decide_case();
    return 0;
}