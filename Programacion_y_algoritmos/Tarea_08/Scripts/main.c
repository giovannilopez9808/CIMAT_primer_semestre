#include "Functions/binary_tree.h"
#include "Functions/hash_table.h"
#include "Functions/sets.h"
int main()
{
    hash_data *hash_table = initialize_hash_table();
    print_all_the_trees(hash_table);
    // node *set1 = obtain_set1();
    // print_preorder(set1);
    // print_inorder(set1);
    // print_postorder(set1);
    // printf("Number of nodes: %d\n", count_nodes(set1));
    return 0;
}
