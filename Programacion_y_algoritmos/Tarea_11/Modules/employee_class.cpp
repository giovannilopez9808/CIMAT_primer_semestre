#include "employee_class.h"
// Constructor de la clase employee_c
employee_c::employee_c(char *name_input,int age_input)
{
    status = 1; 
    set_age(age_input);
    set_name(name_input);
    char curriculum_input[200] = "Esto es un curriculum";
    set_curriculum(curriculum_input);
}
// Destructor de la clase employee_c
employee_c::~employee_c()
{
    delete name;
    delete curriculum;
}
void employee_c::set_curriculum(char *curriculum_input)
{
    curriculum = (char*)malloc(sizeof(char));
    strcpy(curriculum,curriculum_input);
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
    strcpy(name,name_input);
}
// Imprime la informacion del empleado
void employee_c::print_information()
{
    print_status();
    print_name();
    print_age();
    print_curriculum();
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
// Imprime el curriculum del empleado
void employee_c::print_curriculum()
{
    cout << "El curriculum del empleado es el siguiente: \n" << curriculum << endl;
}
