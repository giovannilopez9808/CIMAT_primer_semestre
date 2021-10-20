#include "menu.h"
/* 
Selecciona cada opcion dependiendo de que numero ingreso el usuario
*/
void select_menu(int option, hash_data *hash_table)
{
    switch (option)
    {
    case 1:
        print_maximum_depth_tree(hash_table);
        break;
    case 2:
        insert_node_on_tree(hash_table);
        break;
    case 3:
        delete_node_on_tree(hash_table);
        break;
    case 4:
        print_all_the_trees(hash_table);
        break;
    case 0:
        free(hash_table);
        exit(0);
        break;
    default:
        printf("\nOpcion invalida\n");
        break;
    }
}
/* 
Impresion del menu y activador de cada opcion
*/
void menu(hash_data *hast_table)
{
    int option, aux;
    // Ciclo infinito para que el programa sea finalizado al seleccionar la opcion salir
    while (1)
    {
        printf("\n\nLista de opciones:\n");
        printf("1) Desplegar el arbol con mayor profundidad\n");
        printf("2) Insertar un nodo\n");
        printf("3) Eliminar un nodo\n");
        printf("4) Imprimir todos los arboles\n");
        printf("0) Salir\n");
        printf("\nSeleccione una opcion: ");
        // Lecura de la opcion
        aux = scanf(" %d", &option);
        (void)aux;
        // Selecciona la opcion
        select_menu(option, hast_table);
    }
}