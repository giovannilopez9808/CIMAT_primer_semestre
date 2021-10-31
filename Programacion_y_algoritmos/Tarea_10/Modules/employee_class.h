#ifndef employee_class_H
#define employee_class_H
#include <iostream>
#include <cstdlib>
using namespace std;
// Clase de empleado que contiene el atributo de nane, status y age
class employee_c
{
private:
    char *name;
    int status;
    int age;

public:
    // Inicializador del empleado
    void init_employee(int age_input, char *name_input);
    // Ingresa la edad al empleado
    void set_age(int age_input);
    // Ingresa el nombre al empleado
    void set_name(char *name_input);
    // Imprime la edad del empleado
    void print_age();
    // Imprime el nombre del empleado
    void print_name();
    // Imprime la informacion del empleado
    void print_information();
    // Imprime el status del empleado
    void print_status();
    // Obtiene la edad del empleado
    int get_age() { return age; }
    // Obtiene el nombre del empleado
    char *get_name() { return name; }
};
#endif