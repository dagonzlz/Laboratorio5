#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoubleList {
    Node* head;
    Node* tail;
} DoubleList;

// Funciones para manejar la lista doblemente enlazada
DoubleList* crear_lista();
void insertar_al_inicio(DoubleList* lista, int data);
void insertar_al_final(DoubleList* lista, int data);
void insertar_en_posicion(DoubleList* lista, int data, int posicion);
void eliminar_nodo(DoubleList* lista, int data);
Node* buscar_nodo(DoubleList* lista, int data);
void imprimir_hacia_adelante(DoubleList* lista);
void imprimir_hacia_atras(DoubleList* lista);
void liberar_lista(DoubleList* lista);

#endif

