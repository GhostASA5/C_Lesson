#include <stdio.h>

int main() {

    printf("Your weight: ");

    int weight = 0;

    scanf("%d", &weight);

    if (weight >= 60 && weight <= 90) {
        printf("Go");
    } else {
        printf("No");
    }

}