#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int main(int argc, char *argv[]) {
    int N;

    if (argc == 1) {
        fprintf(stderr, "Wrong use of function. Should be used as %s value", argv[0]);
        return 1;
    }

    if (argc == 2) {
        fprintf(stderr, "Wrong use of function. Should be used as %s value", argv[0]);
        return 2;
    }

    if (argc > 3) {
        fprintf(stderr, "Wrong use of function. Should be used as %s value", argv[0]);
        return 3;
    }

    if (argc == 3) {
        /* Transformamos el valor de N a un entero */
        N = atoi(argv[2]);

        if (N <= 0) {
            fprintf(stderr, "Value for N is zero or negative;");
            return 4;
        }

	/* Dependiendo del valor de argv[1] especificado por el usuario al llamar a ./test,
	se ejecutará la función deseada, con el valor de N especificado */
        if (strcmp(argv[1], "head") == 0) head(N);
        else if (strcmp(argv[1], "tail") == 0) tail(N);
        else if (strcmp(argv[1], "longlines") == 0) longlines(N);
        else {
            fprintf(stderr, "Function not called, arg1 is not head, tail or longlines");
            return 5;
        }
    }
}
