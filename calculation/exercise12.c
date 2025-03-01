#include <stdio.h>

int main() {
    float p, rate, years, amount;

    printf("Enter the principal: ");
    scanf("%f", &p);
    printf("Enter the rate of interest: ");
    scanf("%f", &rate);
    printf("Enter the number of years: ");
    scanf("%f", &years);

    amount = p * (1 + (rate / 100) * years);

    printf("After %.1f years at %.1f%%, the investment will be worth $%.2f\n", years, rate, amount);

    return 0;
}

