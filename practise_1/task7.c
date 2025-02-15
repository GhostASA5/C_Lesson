#include <stdio.h>

int main() {

    double frequency;

    printf("Enter frequency: ");
    scanf("%lf", &frequency);


    if (frequency >= 2.5 && frequency <= 3.5) {
        printf("Stable");
    } else {
        printf("Not stable");
    }

}