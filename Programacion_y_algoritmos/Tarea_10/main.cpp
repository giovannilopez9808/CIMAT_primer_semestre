#include "Modules/employee_class.h"
#include "Modules/employee_struct.h"
using namespace std;
int main()
{
    // Empleado usando estructuras
    employee_s employee1;
    // Empleado usando clases
    employee_c employee2;
    char name[40] = "giovanni";
    // Arquitectura usando estructuras
    cout << "Impreson usando estructuras" << endl;
    init_employee(&employee1, 20, name);
    print_information(employee1);
    // Arquitectura usando clases
    cout << "\nImpreson usando clases" << endl;
    employee2.init_employee(20, name);
    employee2.print_information();
    return 0;
}
