#include "binary_tree.h"
#include "sets.h"
node *obtain_set1()
{
    node *root = NULL;
    root = insert_node(root, 60);
    root = insert_node(root, 15);
    root = insert_node(root, 7);
    root = insert_node(root, 18);
    root = insert_node(root, 80);
    root = insert_node(root, 65);
    root = insert_node(root, 100);
    return root;
}
node *obtain_set2()
{
    node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 12);
    root = insert_node(root, 3);
    root = insert_node(root, 4);
    root = insert_node(root, 6);
    root = insert_node(root, 7);
    root = insert_node(root, 5);
    root = insert_node(root, 11);
    root = insert_node(root, 2);
    root = insert_node(root, 8);
    return root;
}
node *obtain_set3()
{
    node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 11);
    root = insert_node(root, 12);
    root = insert_node(root, 13);
    return root;
}