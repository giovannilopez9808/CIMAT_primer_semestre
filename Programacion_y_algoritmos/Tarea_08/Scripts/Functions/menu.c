#include "menu.h"

void select_menu(int option)
{
    /* 
    Selecciona cada opcion dependiendo de que numero ingreso el usuario
     */
    switch (option)
    {
    default:
        printf("\nOpcion invalida\n");
        break;
    }
}
void menu()
{
    /* 
    Impresion del menu y activador de cada opcion
     */
    int option;
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
        scanf(" %d", &option);
        // Selecciona la opcion
        select_menu(option);
    }
}