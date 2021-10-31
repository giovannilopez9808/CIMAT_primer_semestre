#include "employee_struct.h"
void init_employee(employee_s *employee, int age, char *name)
{
    employee->status = 1;
    set_age(employee, age);
    set_name(employee, name);
}
void set_age(employee_s *employee, int age)
{
    if (age > 18)
    {
        employee->age = age;
    }
    else
    {
        employee->age = -1;
        employee->status = 0;
    }
}
void print_information(employee_s employee)
{
    print_status(employee);
    print_name(employee);
    print_age(employee);
}
void print_age(employee_s employee)
{
    cout << "La edad del empleado es " << employee.age << endl;
}
void set_name(employee_s *employee, char *name)
{
    employee->name = name;
}
void print_name(employee_s employee)
{
    cout << "El nombre del empleado es " << employee.name << endl;
}
void print_status(employee_s employee)
{
    cout << "El status del empleado es " << (employee.status == 1 ? "Trabajando" : "Invalido") << endl;
}