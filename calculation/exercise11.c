#include <stdio.h>

int main() {
    float euros, rate, dollars;

    printf("How many euros are you exchanging? ");
    scanf("%f", &euros);
    printf("What is the exchange rate? ");
    scanf("%f", &rate);

    dollars = euros * rate / 100;

    printf("%.2f euros at an exchange rate of %.2f is %.2f U.S. dollars.\n", euros, rate, dollars);

    return 0;
}

