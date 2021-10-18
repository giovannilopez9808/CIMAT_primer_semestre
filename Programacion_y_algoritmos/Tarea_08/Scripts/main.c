#include "Functions/menu.h"
int main()
{
    hash_data *hash_table = initialize_hash_table();
    menu(hash_table);
    return 0;
}
