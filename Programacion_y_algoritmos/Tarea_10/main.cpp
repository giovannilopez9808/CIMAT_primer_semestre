#include "Modules/employee_class.h"
#include "Modules/employee_struct.h"
using namespace std;
int main()
{
    employee_s employee1;
    employee_c employee2;
    char name[40] = "giovanni";
    employee2.set_name(name);
    employee2.set_age(20);
    employee2.print_age();
    employee2.print_name();
    return 0;
}
