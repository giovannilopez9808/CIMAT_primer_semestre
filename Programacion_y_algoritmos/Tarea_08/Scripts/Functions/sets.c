#include "binary_tree.h"
#include "sets.h"
node *obtain_set1()
{
    node *root = NULL;
    root = Insert_node(root, 1);
    root = Insert_node(root, 2);
    root = Insert_node(root, 3);
    root = Insert_node(root, 4);
    root = Insert_node(root, 5);
    return root;
}
node *obtain_set2()
{
    node *root = NULL;
    root = Insert_node(root, 1);
    root = Insert_node(root, 2);
    root = Insert_node(root, 6);
    root = Insert_node(root, 5);
    return root;
}
node *obtain_set3()
{
    node *root = NULL;
    root = Insert_node(root, 10);
    root = Insert_node(root, 11);
    root = Insert_node(root, 12);
    root = Insert_node(root, 13);
    return root;
}