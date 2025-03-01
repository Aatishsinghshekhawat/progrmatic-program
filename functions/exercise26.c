#include <stdio.h>
#include <math.h>

int calculateMonthsUntilPaidOff(float balance, float apr, float monthlyPayment) {
    float dailyRate = (apr / 100) / 365;
    return ceil(-1.0 / 30.0 * log(1 + balance / monthlyPayment * (1 - pow(1 + dailyRate, 30))) / log(1 + dailyRate));
}

int main() {
    float balance, apr, monthlyPayment;

    printf("What is your balance? ");
    scanf("%f", &balance);
    printf("What is the APR on the card (as a percent)? ");
    scanf("%f", &apr);
    printf("What is the monthly payment you can make? ");
    scanf("%f", &monthlyPayment);

    int months = calculateMonthsUntilPaidOff(balance, apr, monthlyPayment);

    printf("It will take you %d months to pay off this card.\n", months);

    return 0;
}

