#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare_alphabetic(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int compare_length(const void *a, const void *b) {
    size_t len_a = strlen(*(const char **)a);
    size_t len_b = strlen(*(const char **)b);
    return (len_a > len_b) - (len_a < len_b);
}

int count_vowels(const char *str) {
    int count = 0;
    const char *vowels = "aeiouAEIOU";
    while (*str) {
        if (strchr(vowels, *str)) {
            count++;
        }
        str++;
    }
    return count;
}

int compare_vowels(const void *a, const void *b) {
    int vowels_a = count_vowels(*(const char **)a);
    int vowels_b = count_vowels(*(const char **)b);
    return (vowels_a > vowels_b) - (vowels_a < vowels_b);
}

int main() {
    char input[1000];
    char *strings[100];
    int count = 0;

    printf("Введите строки:\n");
    while (1) {
        fgets(input, sizeof(input), stdin);
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        if (strlen(input) == 0) {
            break;
        }

        strings[count] = (char *)malloc((len + 1) * sizeof(char));
        strcpy(strings[count], input);
        count++;
    }

    printf("Выберите режим сортировки (1, 2 или 3):\n");

    int choice;
    scanf("%d", &choice);
    int (*compare_function)(const void *, const void *) = NULL;

    switch (choice) {
        case 1: compare_function = compare_alphabetic; break;
        case 2: compare_function = compare_length; break;
        case 3: compare_function = compare_vowels; break;
    }

    qsort(strings, count, sizeof(char *), compare_function);

    printf("Отсортированные строки:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }

    return 0;
}