#include <stdio.h>
#include <string.h>

int main() {

    char *correct_code = "LAUNCH-2025";
    char code[100];

    fgets(code, sizeof(code), stdin);

    size_t len = strlen(code);
    code[len - 1] = '\0';

    if (strcasecmp(code, correct_code) == 0) {
        printf("Код принят");
    } else {
        printf("Ошибка: неверный код!");
    }

    return 0;
}