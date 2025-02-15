#include <stdio.h>

int main() {

    printf("Enter a char: ");

    char ch;

    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z') {
        printf("Yes");
    } else {
        printf("No");
    }

}