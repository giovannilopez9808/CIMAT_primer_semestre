#include "Modules/employee_class.h"
using namespace std;
int main()
{
    char name_1[40] = "Giovanni", name_2[40] = "Gamaliel";
    // Empleado usando clases
    employee_c employee_c_1(name_1,20), employee_c_2(name_2,16);
    // Arquitectura usando clases
    cout << "Empleado 1"<< endl;
    employee_c_1.print_information();
    cout << "\nEmpleado 2"<< endl;
    employee_c_2.print_information();
    return 0;
}
