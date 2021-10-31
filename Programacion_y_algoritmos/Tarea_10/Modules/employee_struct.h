#ifndef foo_H
#define foo_H
#include <iostream>
using namespace std;
typedef struct Employee
{
    char *name;
    int status;
    int age;
} employee_s;
void init_employee(employee_s *employee, int age, char *name);
void set_age(employee_s *employee, int age);
void set_name(employee_s *employee, char *name);
void print_information(employee_s employee);
void print_status(employee_s employee);
void print_age(employee_s employee);
void print_name(employee_s employee);
#endif
