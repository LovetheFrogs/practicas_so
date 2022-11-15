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
        
            head(3);
            tail(3);
            longlines(3);
            
        

        return 0;
    }
}