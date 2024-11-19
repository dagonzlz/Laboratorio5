#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

// Crear una lista doblemente enlazada vacía
DoubleList* crear_lista() {
    DoubleList* lista = (DoubleList*)malloc(sizeof(DoubleList));
    lista->head = NULL;
    lista->tail = NULL;
    return lista;
}

// Insertar un nodo al inicio de la lista
void  insertar_al_inicio(DoubleList* lista, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = lista->head;

    if (lista->head != NULL) {
        lista->head->prev = new_node;
    } else {
        lista->tail = new_node;
    }

    lista->head = new_node;
}

// Insertar en un nodo al final
void insertar_al_final(DoubleList* lista, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = lista->tail;

    if (lista->tail != NULL) {
        lista->tail->next = new_node;
    } else {
        lista->head = new_node;
    }

    lista->tail = new_node;
}


// Insertar un nodo en una posición específica
void insertar_en_posicion(DoubleList* lista, int data, int posicion) {
    if (posicion <= 0) {
        insertar_al_inicio(lista, data);
        return;
    }

    Node* current = lista->head;
    int indice = 0;

    while (current != NULL && indice < posicion - 1) {
        current = current->next;
        indice++;
    }

    if (current == NULL) {
        insertar_al_final(lista, data);
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = current->next;
    new_node->prev = current;

    if (current->next != NULL) {
        current->next->prev = new_node;
    } else {
        lista->tail = new_node; // si es el ultimo
    }

    current->next = new_node;
}

// ELiminar un nodo por su vlor
void eliminar_nodo(DoubleList* lista, int data) {
    Node* current = lista->head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) return; // Node no encontrado

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        lista->head = current->next; // primer nodo
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        lista->tail = current->prev; // ultimo nodo
    }

    free(current);
}

// Buscar nodo por su valor
Node* buscar_nodo(DoubleList* lista, int data) {
    Node* current = lista->head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL; // por si no encuentra el nodo
}

// imprimir la lista desde el inicio
void imprimir_hacia_adelante(DoubleList* lista) {
    Node* current = lista->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// imprimir desde el final
void imprimir_hacia_atras(DoubleList* lista) {
    Node* current = lista->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// liberando toda la memoria de la lista
void liberar_lista(DoubleList* lista) {
    Node* current = lista->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(lista);
}


