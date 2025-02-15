#include <stdio.h>

int main() {

    double calc_speed;
    double fact_speed;

    printf("Enter calculated speed: ");
    scanf("%lf", &calc_speed);

    printf("Enter fact speed: ");
    scanf("%lf", &fact_speed);


    if (fact_speed - calc_speed > 0.1) {
        printf("Not normal");
    } else {
        printf("Normal");
    }

}