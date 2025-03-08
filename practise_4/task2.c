#include <stdio.h>
#include <strings.h>
#include <string.h>

int main (){
    char str[100];
    fgets(str, sizeof(str), stdin);

    size_t start = strspn(str, "#*");
    size_t len = strcspn(str + start, "#*");

    strndup(str + start, len);

    printf("%zu", len);
    return 0;
}