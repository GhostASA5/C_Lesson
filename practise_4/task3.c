#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[1000];

    fgets(input, sizeof(input), stdin);

    char *names = strtok(input, ";");

    while (names != NULL) {
        printf("%s\n", names);
        names = strtok(NULL, ";");
    }

    free(names);

    return 0;
}