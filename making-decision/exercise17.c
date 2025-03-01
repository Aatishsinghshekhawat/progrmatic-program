#include <stdio.h>

int main() {
    float weight, drinks, alcohol_volume, hours, bac;
    char gender;
    const float ratio_men = 0.73, ratio_women = 0.66, legal_bac = 0.08;

    printf("Enter your weight (in pounds): ");
    scanf("%f", &weight);
    
    printf("Enter number of drinks consumed: ");
    scanf("%f", &drinks);

    printf("Enter alcohol content per drink (in ounces): ");
    scanf("%f", &alcohol_volume);

    printf("Enter hours since last drink: ");
    scanf("%f", &hours);

    printf("Enter gender (M/F): ");
    scanf(" %c", &gender);

    float ratio = (gender == 'M' || gender == 'm') ? ratio_men : ratio_women;
    bac = (drinks * alcohol_volume * 5.14 / weight * ratio) - (0.015 * hours);

    printf("Your BAC is %.2f\n", bac);
    printf("It is %s to drive.\n", (bac >= legal_bac) ? "not legal" : "legal");

    return 0;
}

