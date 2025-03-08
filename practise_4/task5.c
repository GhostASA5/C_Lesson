#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char existed[200];
    fgets(existed, sizeof(existed), stdin);

    char *copy = strdup(existed);

    printf("Оригинал: %s", existed);
    printf("Копия: %s", copy);

    free(copy);

    return 0;
}