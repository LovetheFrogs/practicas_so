#include "libreria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Definimos una constante BUFFERSIZE (tamaño máximo de una línea) */
#define BUFFERSIZE 1024

/* La función check_errors comprobará errores en el argumento N. Este deberá cumplir los siguientes requisitos: 
        + N deberá ser positivo 
   Si no se cumplen eestas condiciones, check_errors devolverá un código de error (1).
   En caso contrario, la función devolverá el valor 0.
   La función será static ya que solo la podrán usar los métodos de librería.c y devolverá un int (el código de error) */
static int check_errors(int N) {
    if (N < 0) return 1;
}

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

    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá NULL */
    if (!curr) return NULL;

    node_t * prv = (node_t *) malloc(sizeof(node_t));

    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá NULL */
    if (!prv) return NULL;

    /* Creamos un nodo nuevo, este será el que deberemos insertar */
    node_t * newNode = (node_t *) malloc(sizeof(node_t));

    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá NULL */
    if (!newNode) return NULL;

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

    /* Damos los valores deseados al nodo a insertar */
    strcpy(newNode -> value, val);
    newNode -> prev = prv;
    newNode -> next = curr;

    /* Si la lista ya tiene elementos, debemos comprobar que no se inserta por el principio o por el final antes de asignar
       los valores de las posiciones previas y siguientes para evitar errores */
    if (*len != 1) {
        if (prv) prv -> next = newNode;
        if (curr) curr -> prev = newNode;
    }

    if ((*len == 1) && (strlen(val) > strlen(list -> value))) {
        /* Si la longitud es 1 e insertamos por el final, solo pondremos list.next a newNode */
        list -> next = newNode;
    } else if (*len == 1) {
        /* En caso de longitud 1 e insercción por el inicio, deberemos mover el inicio de la lista al nuevo inicio */
        list -> prev = newNode;
        list = list -> prev;
    } else if (*len < max) {
        /* En caso de inserción por el inicio (es decir, prv == NULL), deberemos mover el inicio de la lista */
        if (!prv) list = list -> prev;
    } else {
        /* En caso de inserción con lista llena, eliminamos el primer elemento de la lista. Cabe notar que en 
           este caso, nunca insertaremos en la primera posición, ya que el primer elemento siempre será menor al
           valor a insertar, por tanto, quedará insertado entre el primer y segundo elemento, procediendo después
           al borrado del primer elemento de la lista y cambio de la posición a la que apunta la cabecera de la
           lista */
        list = list -> next;
        list -> prev = NULL;
        free(list -> prev);
    }

    /* En caso de que la lista no tenga tamaño máximo, sumamos uno a la longitud ya que siempre añadiremos un elemento */
    if (*len < max) *len += 1;

    /* Devolvemos el puntero al inicio de la lista ordenada */
    return list;
}

/* Función head(N) */
int head(int N) {
    /* Se comprueba que N sea válido */
    if (check_errors(N) == 1) return 1;
    
    /* Creamos un nodo head como inicio de la lista, reservamos memoria para él y apuntamos prev y next a NULL */
    node_t * head;
    head = (node_t *) malloc(sizeof(node_t));

    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá el código de error 2 */
    if (!head) return 2;

    head -> prev = NULL;
    head -> next = NULL;

    /* Creamos un nodo auxiliar usado para añadir elementos */
    node_t * aux = (node_t *) malloc(sizeof(node_t));

    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá el código de error 2 */
    if (!aux) return 2;

    /* Creamos un nodo current y lo apuntamos a head (inicio de la lista) */
    node_t * current = (node_t *) malloc(sizeof(node_t));
    
    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá el código de error 2 */
    if (!current) return 2;
    
    current = head;

    /* Iteramos tantas veces como líneas queramos leer */
    for (int i = 0; i < N; i++) {
        /* Si la linea leida no es NULL, se crea un nodo aux, se enlaza a la lista y se mueve current al nuevo nodo */
        if (fgets(current -> value, BUFFERSIZE, stdin) != NULL) {     /* La sentencia fgets(current -> value...) pone el valor del nodo apuntado por current a la línea leida */
            aux = (node_t *) malloc(sizeof(node_t));

            /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá el código de error 2 */
            if (!aux) return 2;

            if (i == N - 1) break;

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

int tail(int N) {
    /* Se comprueba que N sea válido */
    if (check_errors(N) == 1) return 1;

    /* Creamos un nodo head como inicio de la lista, reservamos memoria para él y apuntamos prev y next a NULL */
    node_t * first;
    first = (node_t *) malloc(sizeof(node_t));

    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá el código de error 2 */
    if (!first) return 2;

    first -> prev = NULL;
    first -> next = NULL; 
    int i = 0; /* numero de línea */

    /* Creamos un nodo auxiliar usado para añadir elementos */
    node_t * aux = (node_t *) malloc(sizeof(node_t));

    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá el código de error 2 */
    if (!aux) return 2;

    /* Creamos un nodo current y lo apuntamos a first (inicio de la lista) */
    node_t * current = first;

    /* Leemos la entrada */
    while (fgets(current -> value, BUFFERSIZE, stdin) != NULL) {

        aux = (node_t *) malloc(sizeof(node_t));

        /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá el código de error 2 */
        if (!aux) return 2;

        aux -> prev = current;
        aux -> next = NULL;
        current -> next = aux;
        current = current -> next;

        /* Si el numero de líneas es menor o igual que N, añadimos un nodo nuevo */
        if (i < N) {
            i++;

        /* Si hemos sobrepasado N, añadimos un nuevo nodo pero ponemos como primero el siguiente para poder borrar la línea almacenada*/
        /* y a así solo guardar las N últimas líneas en memoria*/
        } else {
            first = first -> next;
            free(first -> prev);
            first -> prev = NULL;
        }
    }

    /*Iteramos la lista */
    while (first) {
        /* Escribimos por pantalla el valor actual */
        fputs(first-> value, stdout);

        /* Ponemos current apuntando a first */
        current = first;

        /* Pasamos first al siguiente elemento */
        first = first -> next;

        /* Liberamos el puntero current */
        current = NULL;
        free(current);
    }

    /* Devolvemos 0, es decir, función ejecutada con éxito */
    return 0;
}

/* Función longlines(N) */
int longlines(int N) {   
    /* Se comprueba que N sea válido */
    if (check_errors(N) == 1) return 1;

    /* Declaramos el inicio de la lista que usaremos para guardar las sentencias e inicializamos sus campos */
    node_t * head = (node_t *) malloc(sizeof(node_t));

    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá el código de error 2 */
    if (!head) return 2;

    head -> prev = NULL;
    head -> next = NULL;
    
    /* Declaramos dos variables que usaremos a la hora de recorrer la lista, tail (final de la lista) y aux (usado para borrar la lista tras su uso) */
    node_t * aux = (node_t *) malloc(sizeof(node_t));

    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá el código de error 2 */
    if (!aux) return 2;

    node_t * tail = (node_t *) malloc(sizeof(node_t));

    /* Comprobamos que malloc se haya realizado correctamente, si no, se devolverá el código de error 2 */
    if (!tail) return 2;

    /* Declaramos un string auxiliar, ya que no siempre insertaremos un string en la lista */
    char str[BUFFERSIZE];

    /* Declaramos el tamaño de la lista */
    int size = 0;

    /* Comprobamos todas las lineas del archivo */
    while (fgets(str, BUFFERSIZE, stdin) != NULL) {
        /* Si son candidatas de inserción, llamamos al método insert() con el tamaño máximo, el tamaño actual, la lista y el elemento */
        if ((isFeasible(str, head)) || size != N) head = insert(str, head, &size, N);
        
        /* Como insert devuelve NULL en caso de error, si head es NULL en este punto, se sale con código de error 2 */
        if (!head) return 2;
    }

    /* Apuntamos tail a la cabecera de la lista para recorrerla y averiguar dónde esta el final */
    tail = head;

    /* Recorremos la lista hasta llegar al final. Esta será la nueva ubicación a la que apuntará tail */
    while (tail -> next) {
        tail = tail -> next;
    }

    /* Recorremos la lista desde el final hasta el inicio */
    while (tail) {
        /* Escribimos por pantalla el valor actual */
        fputs(tail -> value, stdout);
        
        /* Apuntamos aux a tail */
        aux = tail;

        /* Avanzamos tail a la posición anterior */
        tail = tail -> prev;

        /* Borramos aux (anterior posición a la que apuntaba tail) */
        free(aux);
    }

    /* Liberamos las variables tail y head */
    tail, head = NULL;
    free(tail);
    free(head);

    /* Devolvemos 0, es decir, función ejecutada con éxito */
    return 0;
}