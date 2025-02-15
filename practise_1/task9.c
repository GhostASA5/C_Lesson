#include <stdio.h>

int main() {

    double seconds;

    printf("Enter seconds: ");
    scanf("%lf", &seconds);

    int m = (int) (seconds / 60);
    double s = seconds - (m * 60);

    printf("%.2f секунд → %d минута(ы) %.2f секунд", seconds, m, s);

}