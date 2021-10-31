#include "Modules/employee_class.h"
#include "Modules/employee_struct.h"
using namespace std;
int main()
{
    // Empleado usando estructuras
    employee_s employee_s_1, employee_s_2;
    // Empleado usando clases
    employee_c employee_c_1, employee_c_2;
    char name_1[40] = "Giovanni", name_2[40] = "Gamaliel";
    // Arquitectura usando estructuras
    cout << "Impreson usando estructuras" << endl;
    init_employee(&employee_s_1, 20, name_1);
    print_information(employee_s_1);
    init_employee(&employee_s_2, 16, name_2);
    print_information(employee_s_2);
    // Arquitectura usando clases
    cout << "\nImpreson usando clases" << endl;
    employee_c_1.init_employee(20, name_1);
    employee_c_1.print_information();
    employee_c_2.init_employee(16, name_2);
    employee_c_2.print_information();
    return 0;
}
