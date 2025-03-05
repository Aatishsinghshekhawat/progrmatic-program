#include<stdio.h>

int main(){

    float rate , year;
    year = 72 / rate;

    
    while (1) {
        printf("What is the rate of return? ");
        if (scanf("%f", &rate) != 1 || rate == 0) {
            printf("Sorry. That's not a valid input.\n");
            while (getchar() != '\n');  // Clear input buffer
        } else {
            break;
        }
    }
    
    printf("It will take %.0f years to double your investment.\n", year);


    return 0;
}