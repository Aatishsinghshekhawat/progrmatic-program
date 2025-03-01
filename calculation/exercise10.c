#include <stdio.h>

int main() {
    float price1, price2, price3;
    int qty1, qty2, qty3;
    const float tax_rate = 0.055;

    printf("Enter the price of item 1: ");
    scanf("%f", &price1);
    printf("Enter the quantity of item 1: ");
    scanf("%d", &qty1);

    printf("Enter the price of item 2: ");
    scanf("%f", &price2);
    printf("Enter the quantity of item 2: ");
    scanf("%d", &qty2);

    printf("Enter the price of item 3: ");
    scanf("%f", &price3);
    printf("Enter the quantity of item 3: ");
    scanf("%d", &qty3);

    float subtotal = (price1 * qty1) + (price2 * qty2) + (price3 * qty3);
    float tax = subtotal * tax_rate;
    float total = subtotal + tax;

    printf("Subtotal: $%.2f\nTax: $%.2f\nTotal: $%.2f\n", subtotal, tax, total);

    return 0;
}

