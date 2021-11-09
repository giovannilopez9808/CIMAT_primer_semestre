#ifndef employee_class_H
#define employee_class_H
#include <iostream>
#include <cstdlib>
#include<string.h>
using namespace std;
// Clase de empleado que contiene el atributo de nane, status y age
class employee_c
{
private:
    char *name;
    char* curriculum;
    int status;
    int age;

public:
    // Inicializador del empleado
    employee_c(char* name_input,int age_input);
    ~employee_c();
    // Ingresa un curriculum
    void set_curriculum(char *curriculum_input);
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
    void print_curriculum();
    // Obtiene la edad del empleado
    int get_age() { return age; }
    // Obtiene el nombre del empleado
    char *get_name() { return name; }
};
#endif
