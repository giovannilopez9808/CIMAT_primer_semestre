#include "employee_class.h"
// Inicializador del empleado
void employee_c::init_employee(int age_input, char *name_input)
{
    // Inicializador del status
    status = 1;
    // Inicializador de la edad
    set_age(age_input);
    // Inicializador del nombre
    set_name(name_input);
}
// Ingresa la edad al empleado
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
// Ingresa el nombre al empleado
void employee_c::set_name(char *name_input)
{
    name = (char *)malloc(sizeof(char));
    name = name_input;
}
// Imprime la informacion del empleado
void employee_c::print_information()
{
    print_status();
    print_name();
    print_age();
}
// Imprime el nombre del empleado
void employee_c::print_name()
{
    cout << "El nombre del empleado es " << name << endl;
}

// Imprime la edad del empleado
void employee_c::print_age()
{
    cout << "La edad del empleado es " << age << endl;
}
// Imprime el status del empleado
void employee_c::print_status()
{
    cout << "El status del empleado es " << (status == 1 ? "Trabajando" : "Invalido") << endl;
}