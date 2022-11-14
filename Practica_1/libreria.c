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
    /* Creamos un nodo head como inicio de la lista, reservamos memoria para él y apuntamos prev y next a NULL */
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head -> prev = NULL;
    head -> next = NULL; 
    int i = 0; /* numero de línea */

    /* Creamos un nodo auxiliar usado para añadir elementos */
    node_t * aux;

    /*Creamos un nodo auxiliar (llamado first) utilizado para almacenar el primer nodo*/
    node_t * first;

    /* Creamos un nodo current y lo apuntamos a head (inicio de la lista) */
    node_t * current = head;

    /* Leemos la entrada */
    while (fgets(current -> value, BUFFERSIZE, stdin) != NULL) {

        /* Si el numero de líneas es menor o igual que N, añadimos un nodo nuevo */
        if (i <= N) {

            /* Guardamos el primer nodo */
            if(i == 0){
                first = current;
            }

            aux = (node_t *) malloc(sizeof(node_t));
            aux -> prev = current;
            aux -> next = NULL;
            current -> next = aux;
            current = current -> next;
            i++;

        /* Si hemos sobrepasado N, añadimos un nuevo nodo pero ponemos como primero el siguiente para poder borrar la línea almacenada*/
        /* y a así solo guardar las N últimas líneas en memoria*/
        } else {
            aux = (node_t *) malloc(sizeof(node_t));
            aux -> prev = current;
            aux -> next = NULL;
            current -> next = aux;
            current = current -> next;
            first = first -> next;
            free(first -> prev);
            first -> prev = NULL;
        }
    }

    /* Liberamos memoria y apuntamos current de nuevo a head para recorrer la lista de nuevo */
    free(aux);

    /*Iteramos la lista */
    while (head) {
        /* Escribimos por pantalla el valor actual */
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

    /* Devolvemos 0, es decir, función ejecutada con éxito */
    return 0;

}

int longlines(int N) {
    /* TODO longlines implementation */
}