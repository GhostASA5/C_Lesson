#include <stdio.h>

int main() {

    int date;

    printf("Enter mission date: ");
    scanf("%d", &date);

    int current_date = 20250211;


    if (date > current_date) {
        printf("This mission is in the future");
    } else {
        printf("This mission is not in the future");
    }

}