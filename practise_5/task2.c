#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void remove_spaces(char *str) {
    char *dst = str;
    while (*str) {
        if (*str != ' ') {
            *dst++ = *str;
        }
        str++;
    }
    *dst = '\0';
}

void replace_vowels(char *str) {
    char *vowels = "aeiouAEIOU";
    while (*str) {
        if (strchr(vowels, *str)) {
            *str = '*';
        }
        str++;
    }
}

void invert_case(char *str) {
    while (*str) {
        if (isalpha((char)*str)) {
            if (islower((char)*str)) {
                *str = toupper((char)*str);
            } else {
                *str = tolower((char)*str);
            }
        }
        str++;
    }
}

typedef void (*StringProcessor)(char *);

int main() {
    StringProcessor processors[] = {
            remove_spaces,
            replace_vowels,
            invert_case
    };

    char string[1000];
    char *str;

    printf("Введите строку: ");
    fgets(string, sizeof(string), stdin);

    size_t len = strlen(string);
    str = (char *)malloc((len + 1) * sizeof(char));
    strcpy(str, string);


    printf("Выберите функцию обработки (1, 2 или 3): ");
    int choice;
    scanf("%d", &choice);
    processors[choice - 1](str);
    printf("Результат: %s\n", str);

    free(str);

    return 0;
}
