#include <stdio.h>
#include <string.h>

int head(int n){
    int i;
    char *buffer = NULL;
    size_t bufsize;

    if (n == NULL){
        n = 10;
    }
    
    for (i = 0; i <= n; i++)
    {
        printf("%d\n", getline(&buffer,&bufsize,stdin));
    }
    return 0;
}

int tail(int n) {
    char text[100];
    int i = 0;
    char *buffer = NULL;
    size_t bufsize;

    text[i] = getline(&buffer, &bufsize, stdin);

    while (text[i] != -1) {
        i++;
        text[i] == getline(&buffer, &bufsize, stdin);
    }

    for (int j = i - 1; j <= i - n - 1; j--) {
        printf("%d\n", text[j]);
    }

    return 0;
}

int longlines(int n) {
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
                t = strcp(*(ptr + i));
                *(ptr + i) = strcp(*(ptr + j));
                *(ptr + j) = strcp(t);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d\n", *(ptr + i));
    }
    
}