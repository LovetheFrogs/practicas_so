#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int main(int argc, char *argv[]) {
    int N;
    char h[] = "head";
    char t[] = "tail";
    char ll[] = "longlines";
    
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
        N = atoi(argv[2]);

        if (N <= 0) {
            fprintf(stderr, "Value for N is zero or negative;");
            return 4;
        }

        if (strcmp(argv[1], h) == 0) head(N);
        else if (strcmp(argv[1], t) == 0) tail(N);
        else if (strcmp(argv[1], ll) == 0) longlines(N);
        else {
            fprintf(stderr, "Function not called, arg1 is not head, tail or longlines");
            return 5;
        }
    }
}