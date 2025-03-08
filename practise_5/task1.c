#include <stdio.h>
#include <string.h>
#include <ctype.h>


void upper(char *str) {
    while (*str) {
        *str = toupper((char)*str);
        str++;
    }
}

void lower(char *str) {
    while (*str) {
        *str = tolower((char)*str);
        str++;
    }
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

typedef struct {
    const char *name;
    void (*func)(char *);
} Command;

int main() {

    Command commands[] = {
            {"upper", upper},
            {"lower", lower},
            {"reverse", reverse},
            {"exit", NULL}
    };

    char command[100];
    char str[100];

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);


    while (1) {
        printf("Введите команду: ");
        fgets(command, sizeof(command), stdin);

        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
            if (strcmp(command, commands[i].name) == 0) {
                if (commands[i].func == NULL) {
                    printf("Выход из программы.\n");
                    return 0;
                } else {
                    commands[i].func(str);
                    printf("Результат: %s", str);
                    break;
                }
            }
        }
    }
}