#ifndef foo_H
#define foo_H
#include <iostream>
using namespace std;
// Estructura del empleado con los atributos name, status y age
typedef struct Employee
{
    char *name;
    int status;
    int age;
} employee_s;
// Inicializador de el empleado
void init_employee(employee_s *employee, int age, char *name);
// Registra la edad a el empleado, si es menor a 18, se invalida el status
void set_age(employee_s *employee, int age);
// Registra el nombre a el empleado
void set_name(employee_s *employee, char *name);
// Imprime en pantalla la información del empleado
void print_information(employee_s employee);
// Imprime el status del empleado
void print_status(employee_s employee);
// Imprime la edad del empleado
void print_age(employee_s employee);
// Imprime el nombre del empleado
void print_name(employee_s employee);
#endif
