#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int main(int argc, char ** argv) {
    FILE * file;
    char curr;

    file = open(argv[1], 0);

    while ((curr = getc(file)) != EOF) {
        printf("%c\n", curr);
    }

    return 0;
}