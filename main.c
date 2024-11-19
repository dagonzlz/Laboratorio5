#include <stdio.h>
#include "double_list.h"

int main() {
    // Crear una nueva lista doblemente enlazada
    DoubleList* lista = crear_lista();

    // Insertar nodos al inicio
    printf("Insertando 10 al inicio...\n");
    insertar_al_inicio(lista, 10);
    printf("Insertando 20 al inicio...\n");
    insertar_al_inicio(lista, 20);
    printf("Insertando 30 al inicio...\n");
    insertar_al_inicio(lista, 30);
    printf("Lista actual (hacia adelante): ");
    imprimir_hacia_adelante(lista);

    // Insertar nodos al final
    printf("\nInsertando 40 al final...\n");
    insertar_al_final(lista, 40);
    printf("Insertando 50 al final...\n");
    insertar_al_final(lista, 50);
    printf("Lista actual (hacia adelante): ");
    imprimir_hacia_adelante(lista);

    // Insertar un nodo en una posición específica
    printf("\nInsertando 25 en la posición 2...\n");
    insertar_en_posicion(lista, 25, 2);
    printf("Lista actual (hacia adelante): ");
    imprimir_hacia_adelante(lista);

    // Buscar un nodo
    int buscar = 25;
    printf("\nBuscando el nodo con el dato %d...\n", buscar);
    Node* encontrado = buscar_nodo(lista, buscar);
    if (encontrado) {
        printf("Nodo encontrado con dato: %d\n", encontrado->data);
    } else {
        printf("Nodo no encontrado.\n");
    }

    // Eliminar un nodo por su valor
    int eliminar = 20;
    printf("\nEliminando el nodo con el dato %d...\n", eliminar);
    eliminar_nodo(lista, eliminar);
    printf("Lista actual (hacia adelante): ");
    imprimir_hacia_adelante(lista);

    // Imprimir la lista en ambas direcciones
    printf("\nLista actual (hacia adelante): ");
    imprimir_hacia_adelante(lista);
    printf("Lista actual (hacia atrás): ");
    imprimir_hacia_atras(lista);

    // Liberar toda la memoria de la lista
    printf("\nLiberando toda la memoria de la lista...\n");
    liberar_lista(lista);

    return 0;
}

