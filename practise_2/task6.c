#include <stdio.h>
#include <stdlib.h>


typedef enum {
    GASOLINE,
    DIESEL,
    ELECTRIC
} EngineType;

typedef struct {
    char brand[50];
    char model[50];
    int year;
    EngineType engineType;
} Vehicle;

int main() {

    int n;
    scanf("%d", &n);


    Vehicle* vehicles = (Vehicle*)malloc(n * sizeof(Vehicle));

    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %d", vehicles[i].brand, vehicles[i].model, &vehicles[i].year, &vehicles[i].engineType);
    }

    for (int i = 0; i < n; i++) {
        printf("Vehicle: %s %s\n", vehicles[i].brand, vehicles[i].model);
        printf("Year: %d\n", vehicles[i].year);
        printf("Engine Type: %u\n\n", vehicles[i].engineType);
    }

    free(vehicles);
}