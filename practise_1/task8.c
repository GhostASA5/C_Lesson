#include <stdio.h>

int main() {

    int weight;

    printf("Enter weight: ");
    scanf("%d", &weight);


    if (weight % 4 == 0) {
        printf("Груз можно распределить по %d кг.", weight / 4);
    } else {
        printf("Груз нельзя распределить");
    }

}