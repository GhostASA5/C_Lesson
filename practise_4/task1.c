#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main() {
    char ships[100][50];
    int count = 3;

    for (int i = 0; i < count; i++) {
        char ship[50];
        fgets(ship, sizeof(ship), stdin);
        ship[strcspn(ship, "\n")] = 0;
        strcpy(ships[i], ship);
    }

    char* result = "Не найдено";

    for (int i = 0; i < count; i++) {
        if (strlen(ships[i]) >= 2) {
            char first = toupper(ships[i][0]);
            char second = toupper(ships[i][1]);

            if (first == 'S' && second == 'S') {
                result = ships[i];
                break;
            }
        }
    }

    printf("%s\n", result);
    free(result);

    return 0;
}