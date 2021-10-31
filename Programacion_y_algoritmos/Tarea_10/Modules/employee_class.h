#ifndef employee_class_H
#define employee_class_H
#include <iostream>
#include <cstdlib>
using namespace std;
class employee_c
{
private:
    char *name;
    int status;
    int age;

public:
    void init_employee(int age_input, char *name_input);
    void set_age(int age_input);
    void set_name(char *name_input);
    void print_age();
    void print_name();
    void print_information();
    void print_status();
    int get_age() { return age; }
    char *get_name() { return name; }
};
#endif