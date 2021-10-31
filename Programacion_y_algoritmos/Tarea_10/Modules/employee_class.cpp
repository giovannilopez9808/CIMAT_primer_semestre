#include "employee_class.h"
void employee_c::init_employee(int age_input, char *name_input)
{
    status = 1;
    set_age(age_input);
    set_name(name_input);
}
void employee_c::set_age(int age_input)
{
    if (age_input > 18)
        age = age_input;
    else
    {
        age = -1;
        status = 0;
    }
}

void employee_c::set_name(char *name_input)
{
    name = (char *)malloc(sizeof(char));
    name = name_input;
}
void employee_c::print_information()
{
    print_status();
    print_name();
    print_age();
}
void employee_c::print_name()
{
    cout << "El nombre del empleado es " << name << endl;
}

void employee_c::print_age()
{
    cout << "La edad del empleado es " << age << endl;
}
void employee_c::print_status()
{
    cout << "El status del empleado es " << (status == 1 ? "Trabajando" : "Invalido") << endl;
}