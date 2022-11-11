#include "libreria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 1024

typedef struct node 
{
        struct node * prev;
        char value[BUFFERSIZE];
        struct node * next;
} node_t;

int head(int N) {
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head -> prev = NULL;
    head -> next = NULL;

    node_t * aux;
    node_t * current = head;

    while (fgets(current -> value, BUFFERSIZE, stdin) != NULL) {
        aux = (node_t *) malloc(sizeof(node_t));
        aux -> prev = current;
        aux -> next = NULL;
        current -> next = aux;
        current = current -> next;
    }
    free(aux);
    current = head;
    for (int i = 1; i <= N; i++) {
        fputs(current -> value, stdout);
        current = current -> next;
    }

    current = head;
    while (current -> next != NULL) {
        current = current -> next;
        free(current -> prev);
    }
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