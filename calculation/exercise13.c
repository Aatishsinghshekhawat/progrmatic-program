#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, years, times_per_year, amount;

    printf("What is the principal amount? ");
    scanf("%lf", &principal);
    
    printf("What is the rate? ");
    scanf("%lf", &rate);
    
    printf("What is the number of years? ");
    scanf("%lf", &years);
    
    printf("What is the number of times the interest is compounded per year? ");
    scanf("%lf", &times_per_year);

    // Convert percentage rate to decimal and calculate compound interest
    amount = principal * pow(1 + (rate / 100) / times_per_year, times_per_year * years);

    printf("%.2f invested at %.1f%% for %.0f years compounded %.0f times per year is %.2f.\n",
           principal, rate, years, times_per_year, amount);

    return 0;
}

