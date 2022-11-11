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
    current = head;

    /* Iteramos en la lista hasta llegar al final */
    while (current -> next != NULL) {
        /* Escribimos por pantalla el valor de current */
        fputs(current -> value, stdout);

        /* Pasamos al siguiente elemento */
        current = current -> next;

        /* Liberamos el espacio ocupado por el elemento anterior */
        free(current -> prev);
    }

    return 0;
}

int tail(int N) {
    char text[100];
    int i = 0;
    char *buffer = NULL;
    size_t bufsize;

    text[i] = getline(&buffer, &bufsize, stdin);

    while (text[i] != -1) {
        i++;
        text[i] == getline(&buffer, &bufsize, stdin);
    }

    for (int j = i - 1; j <= i - N - 1; j--) {
        printf("%s\n", text[j]);
    }

    return 0;
}

int longlines(int N) {
    char text[100];
    int i = 0;
    char *buffer = NULL;
    size_t bufsize;

    text[i] = getline(&buffer, &bufsize, stdin);

    while (text[i] != -1) {
        i++;
        text[i] == getline(&buffer, &bufsize, stdin);
    }

    return 0;
}

static void sort(int lenght, char *ptr, int n){
    int i, j;
    char *t;

    for (i = 0; i < lenght; i++) {
        for (j = i + 1; j < lenght; j++) {
            if (strlen(*(ptr + j)) < strlen(*(ptr + i))) {
                strcpy(t, *(ptr + i));
                strcpy(*(ptr + i), *(ptr + j));
                strcpy(*(ptr + j) , t);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%s\n", *(ptr + i));
    }
}