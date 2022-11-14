#include "libreria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Definimos una constante BUFFERSIZE (tamaño máximo de una línea) */
#define BUFFERSIZE 1024

/* Definimos el nodo de una lista doblemente enlazada */
typedef struct node 
{
        struct node * prev;                 /* Puntero al nodo anterior */
        char value[BUFFERSIZE];             /* Valor de esa posición */
        struct node * next;                 /* Puntero al nodo siguiente */
} node_t;

/* La función isFeasible es usada en el método long lines para determinar si un valor es añadido a los elementos mas largos o no. 
   Esta definida cómo static para evitar que sea usada fuera del archivo librería.c */
static bool isFeasible(char check[BUFFERSIZE], node_t * list) {
    return strlen(list -> value) < strlen(check);       /* Devuelve si el valor es mayor que el más pequeño de la lista */
}

/* La función insert toma una lista dinámica, un valor, la longitud de la lista, y el tamaño maximo
   y añade el elemento en la posición adecuada para que este ordenada en orden ascendente
   y no supere el tamaño max. Esta definida cómo static para evitar que sea usada fuera del archivo librería.c */
static node_t * insert(char val[BUFFERSIZE], node_t * list, int * len, int max) {
    /* Se definen dos nodos, usados para ver donde insertaremos el valor (el anterior a la posición nueva y la posición siguiente)*/
    node_t * curr = (node_t *) malloc(sizeof(node_t));
    node_t * prv = (node_t *) malloc(sizeof(node_t));

    /* Apuntamos curr al inicio de la lista, y prv a su anterior (nulo) */
    curr = list;
    prv = NULL;

    /* Si la lista esta vacía, no realizamos comprobaciones. Directamente aumentamos el tamaño de la lista a 1 y ponemos el valor de ese nodo a elemento */
    if (*len == 0) {
        strcpy(list -> value, val);
        *len += 1;
        return list;
    }

    /* Este while recorre la lista hasta encontrar la posición en la que deberemos de insertar el elemento. 
       La condicion es curr != NULL ya que puede darse el caso de tener que insertar al final */
    while (curr) {
        if (strlen(curr -> value) < strlen(val)) {
            prv = curr;
            curr = curr -> next;
        }
        /* Se usa esta sentencia para salir del bucle en caso de haber encontrado la posición adecuada */
        else break;
    }

    node_t * newNode = (node_t *) malloc(sizeof(node_t));

    strcpy(newNode -> value, val);
    newNode -> prev = prv;
    newNode -> next = curr;

    if (*len < max) *len += 1;
    if (*len != 1) {
        if (prv) prv -> next = newNode;
        if (curr) curr -> prev = newNode;
    }

    if ((*len == 1) && (strlen(val) > strlen(list -> value))) {
        list -> next = newNode;
    } else if (*len == 1) {
        list -> prev = newNode;
        list = list -> prev;
    } else if (*len < max) {
        if (!prv) list = list -> prev;
    } else {
        list = list -> next;
        free(list -> prev);
    }

    free(prv);
    free(curr);
    free(newNode);

    return list;
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
    while (head) {
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
    node_t * head = (node_t *) malloc(sizeof(node_t));
    head -> prev = NULL;
    head -> next = NULL;

    node_t * aux = (node_t *) malloc(sizeof(node_t));
    node_t * tail = (node_t *) malloc(sizeof(node_t));

    char aux[BUFFERSIZE];
    int size = 0;

    while (fgets(aux, BUFFERSIZE, stdin) != NULL) {
        if ((isFeasible(aux, head)) || size != N) head = insert(aux, head, &size, N);
    }

    tail = head;

    while (tail -> next) {
        tail = tail -> next;
    }

    while (tail) {
        fputs(tail -> value, stdout);
        aux = tail;
        tail = tail -> prev;
        free(aux);
    }

    free(tail);
    free(head);

    return 0;
}