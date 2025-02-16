#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int intValue;
    float floatValue;
    char stringValue[100];
} Data;

int main() {

    Data* data = (Data *)malloc(sizeof(Data));
    int choice;

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            scanf("%d", &data->intValue);
            break;
        case 2:
            scanf("%f", &data->floatValue);
            break;
        case 3:
            scanf("%s", data->stringValue);
            break;
    }

    switch (choice) {
        case 1:
            printf("Integer: %d\n", data->intValue);
            break;
        case 2:
            printf("Float: %.2f\n", data->floatValue);
            break;
        case 3:
            printf("String: %s\n", data->stringValue);
            break;
    }

}