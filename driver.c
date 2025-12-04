#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char command[50];
    snprintf(command, sizeof(command), "gcc -E -P %s.c -o %s.i", argv[1], argv[2]);

    if(system(command) != 0) {
        printf("something went wrong...");
        exit(-1);
    }

    return 0;
}