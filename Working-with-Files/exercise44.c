#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    float price;
    int quantity;
} Product;

int main() {
    Product products[] = {
        {"Widget", 25.00, 5},
        {"Thing", 15.00, 5},
        {"Doodad", 5.00, 10}
    };
    
    int numProducts = sizeof(products) / sizeof(products[0]);
    char searchName[20];

    while (1) {
        printf("What is the product name? ");
        scanf("%s", searchName);

        int found = 0;
        for (int i = 0; i < numProducts; i++) {
            if (strcasecmp(products[i].name, searchName) == 0) {
                printf("Name: %s\n", products[i].name);
                printf("Price: $%.2f\n", products[i].price);
                printf("Quantity on hand: %d\n", products[i].quantity);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Sorry, that product was not found in our inventory.\n");
        }
    }

    return 0;
}
