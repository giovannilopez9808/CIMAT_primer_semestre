#include "Functions/binary_tree.h"
#include "Functions/sets.h"
// #include "Functions/hash_table.h"
int main()
{
    node *set1 = obtain_set2();
    print_preorder(set1);
    print_inorder(set1);
    print_postorder(set1);
    return 0;
}
