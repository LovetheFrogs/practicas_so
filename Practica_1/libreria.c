#include "libreria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Definimos una constante BUFFERSIZE (tamaño máximo de una línea) */
#define BUFFERSIZE 1024

/* Definimos el nodo de una lista doblemente enlazada */
typedef struct node 
{
        struct node * prev;                 /* Puntero al nodo anterior */
        char value[BUFFERSIZE];             /* Valor de esa posición */
        struct node * next;                 /* Puntero al nodo siguiente */
} node_t;

/* function to swap data of two nodes a and b*/
void swap(node_t * a, node_t * b) 
{ 
    char temp[BUFFERSIZE];
    strcpy(temp, a -> value); 
    strcpy(a -> value, b -> value); 
    strcpy(b -> value, temp); 
} 

void bubbleSort(node_t * start) 
{
    int swapped; 
    
    node_t * ptr1;
    ptr1 = (node_t *) malloc(sizeof(node_t));

    node_t * lptr;
    lptr = (node_t *) malloc(sizeof(node_t));
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1 -> next != lptr) 
        { 
            if (strlen(ptr1 -> value) < strlen(ptr1 -> next -> value)) 
            { 
                swap(ptr1, ptr1 -> next); 
                swapped = 1; 
            } 
            ptr1 = ptr1 -> next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

/* Función head(N) */
int head(int N) {
    /* Creamos un nodo head como inicio de la lista, reservamos memoria para él y apuntamos prev y next a NULL */
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head -> prev = NULL;
    head -> next = NULL;

    /* Creamos un nodo auxiliar usado para añadir elementos */
    node_t * aux;

    /* Creamos un nodo current y lo apuntamos a head (inicio de la lista) */
    node_t * current = head;

    /* Iteramos tantas veces como líneas queramos leer */
    for (int i = 0; i <= N; i++) {
        /* Si la linea leida no es NULL, se crea un nodo aux, se enlaza a la lista y se mueve current al nuevo nodo */
        if (fgets(current -> value, BUFFERSIZE, stdin) != NULL) {     /* La sentencia fgets(current -> value...) pone el valor del nodo apuntado por current a la línea leida */
            aux = (node_t *) malloc(sizeof(node_t));
            aux -> prev = current;
            aux -> next = NULL;
            current -> next = aux;
            current = current -> next;
        }
        /* Si se ha llegado al final antes de que i > n, se sale del bucle */
        else break;
    }

    /* En caso de necesitar leer todo stdin, cambiar el FOR por este WHILE

    while (fgets(current -> value, BUFFERSIZE, stdin) != NULL) {
        if (i <= N) {
            aux = (node_t *) malloc(sizeof(node_t));
            aux -> prev = current;
            aux -> next = NULL;
            current -> next = aux;
            current = current -> next;
        }  
    }

    */
    
    /* Liberamos memoria y apuntamos current de nuevo a head para recorrer la lista de nuevo */
    free(aux);

    /* Iteramos en la lista hasta llegar al final */
    while (head != NULL) {
        /* Escribimos por pantalla el valor de current */
        fputs(head-> value, stdout);

        /* Ponemos current apuntando a head */
        current = head;

        /* Pasamos head al siguiente elemento */
        head = head -> next;

        /* Liberamos el puntero current */
        free(current);
    }

    /* Liberamos el puntero head */
    free(head);

    return 0;
}

int tail(int N) {
    /* Falta implementar tail (para ti ines uwu) */
}

int longlines(int N) {
    /* Creamos un nodo head como inicio de la lista, reservamos memoria para él y apuntamos prev y next a NULL */
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head -> prev = NULL;
    head -> next = NULL;

    /* Creamos un nodo auxiliar usado para añadir elementos */
    node_t * aux;

    /* Creamos un nodo current y lo apuntamos a head (inicio de la lista) */
    node_t * current = head;

    while (fgets(current -> value, BUFFERSIZE, stdin) != NULL) {
        aux = (node_t *) malloc(sizeof(node_t));
        aux -> prev = current;
        aux -> next = NULL;
        current -> next = aux;
        current = current -> next;
    }

    free(aux);
    bubbleSort(head);

    for (int i = 0; i <= N; i++) {
        fputs(head -> value, stdout);
        /* Ponemos current apuntando a head */
        current = head;

        /* Pasamos head al siguiente elemento */
        head = head -> next;

        /* Liberamos el puntero current */
        free(current);
    }
}