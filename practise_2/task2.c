#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

int main() {

    int n;
    scanf("%d", &n);

    Item* items = (Item*)malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        scanf("%s %d %f", items[i].name, &items[i].quantity, &items[i].price);
    }

    for (int i = 0; i < n; i++) {
        printf("Item: %s\n", items[i].name);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: %.2f\n\n", items[i].price);
    }

    free(items);
}