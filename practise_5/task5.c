#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *memory = NULL;
size_t memory_size = 0;

void alloc(char *args) {
    size_t size = atoi(args);

    if (memory != NULL) {
        free(memory);
    }

    memory = (char *)malloc(size * sizeof(char));
    memory_size = size;
    printf("Память выделена.\n");
}

void cmd_free() {
    free(memory);
    memory = NULL;
    memory_size = 0;
    printf("Память освобождена.\n");
}

void cmd_write(char *args) {
    size_t text_length = strlen(args);
    if (text_length >= memory_size) {
        printf("Ошибка: текст слишком длинный для выделенной памяти.\n");
        return;
    }
    strcpy(memory, args);
    printf("Текст записан в память.\n");
}

void cmd_print() {
    printf("Текущие данные в памяти: %s\n", memory);
}

void cmd_exit() {
    if (memory != NULL) {
        free(memory);
    }
    printf("Завершение программы.\n");
    exit(0);
}

typedef struct {
    char *name;
    void (*func)(char *);
} Command;

int main() {
    Command commands[] = {
            {"alloc", alloc},
            {"free", cmd_free},
            {"write", cmd_write},
            {"print", cmd_print},
            {"exit", cmd_exit}
    };

    char input[1000];

    while (1) {
        printf("Введите команду: ");
        fgets(input, sizeof(input), stdin);

        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        char *command = strtok(input, " ");
        char *args = strtok(NULL, "");

        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
            if (strcmp(command, commands[i].name) == 0) {
                commands[i].func(args);
                break;
            }
        }
    }
}