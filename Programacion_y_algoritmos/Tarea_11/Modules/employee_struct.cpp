#include "employee_struct.h"
// Inicializador de el empleado

void init_employee(employee_s *employee, int age, char *name)
{
    // Inicializa el status
    employee->status = 1;
    // Inicializa el nombre
    set_age(employee, age);
    // Inicializa el nombre
    set_name(employee, name);
}
// Registra la edad a el empleado, si es menor a 18, se invalida el status
void set_age(employee_s *employee, int age)
{
    if (age > 18)
    {
        employee->age = age;
    }
    else
    {
        employee->age = -1;
        // Invalidacion del status
        employee->status = 0;
    }
}
// Imprime en pantalla la información del empleado
void print_information(employee_s employee)
{
    print_status(employee);
    print_name(employee);
    print_age(employee);
}
// Imprime la edad del empleado
void print_age(employee_s employee)
{
    cout << "La edad del empleado es " << employee.age << endl;
}
// Registra el nombre a el empleado
void set_name(employee_s *employee, char *name)
{
    employee->name = name;
}
// Imprime el nombre del empleado
void print_name(employee_s employee)
{
    cout << "El nombre del empleado es " << employee.name << endl;
}
// Imprime el status del empleado
void print_status(employee_s employee)
{
    cout << "El status del empleado es " << (employee.status == 1 ? "Trabajando" : "Invalido") << endl;
}