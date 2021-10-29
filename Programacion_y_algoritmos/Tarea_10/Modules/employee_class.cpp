#include "employee_class.h"
void employee_c::set_age(int age_input)
{
    if (age_input > 18)
        age = age_input;
    else
    {
        age = -1;
    }
}

void employee_c::set_name(char *name_input)
{
    name = (char *)malloc(sizeof(char));
    name = name_input;
}

void employee_c::print_age()
{
    cout << "El nombre del empleado es " << name << endl;
}

void employee_c::print_name()
{
    cout << "Tiene la edad de " << age << endl;
}
