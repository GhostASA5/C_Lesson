#include <stdio.h>

int main() {

    printf("Enter distance: ");

    int dist = 0;

    scanf("%d", &dist);

    if (dist < 500) {
        printf("Yes");
    } else {
        printf("No");
    }

}