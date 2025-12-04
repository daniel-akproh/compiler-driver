#include <stdio.h>
#include <stdlib.h>

int main() {
    system("ls");

    system("echo 'some content' > test.txt");
    system("cat test.txt");

    if (system("abc") != 0) {
        // if unsuccessful, will return a nonzero value
        printf("\nerror executing command .......\n");
    }

    return 0;
}