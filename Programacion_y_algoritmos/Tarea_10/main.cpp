#include "Modules/employee_class.h"
#include "Modules/employee_struct.h"
using namespace std;
int main()
{
    employee_s employee1;
    employee_c employee2;
    char name[40] = "giovanni";
    cout << "Impreson usando estructuras" << endl;
    init_employee(&employee1, 20, name);
    print_information(employee1);
    cout << "\nImpreson usando clases" << endl;
    employee2.init_employee(20, name);
    employee2.print_information();
    return 0;
}
