#include <stdio.h>
#include "libreria.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Usage: %s number_of_n, n1, n2...\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        fprintf(stderr, "Usage: %s number_of_n, n1, n2...\n", argv[0]);
        return 2;
    }

    if (argc >= 3) {
        int j;
        for (int i = 2; i < (int) argv[1] + 2; i++) {
            j = (int) argv[i];
            head(5);
            longlines(5);
            tail(j);
            longlines(j);
            printf("Test case for n = %d\n completed", j);
        }

        return 0;
    }
}