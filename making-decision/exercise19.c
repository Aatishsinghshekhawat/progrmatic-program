#include <stdio.h>

int main() {
    float weight, height, bmi;

    printf("Enter your weight (in pounds): ");
    scanf("%f", &weight);
    
    printf("Enter your height (in inches): ");
    scanf("%f", &height);

    bmi = (weight / (height * height)) * 703;

    printf("Your BMI is %.1f.\n", bmi);
    
    if (bmi < 18.5)
        printf("You are underweight. You should see your doctor.\n");
    else if (bmi <= 25)
        printf("You are within the ideal weight range.\n");
    else
        printf("You are overweight. You should see your doctor.\n");

    return 0;
}

