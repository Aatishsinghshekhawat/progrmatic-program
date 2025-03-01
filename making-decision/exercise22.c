#include <stdio.h>

int main() {
    int num1, num2, num3, largest;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the third number: ");
    scanf("%d", &num3);

    if (num1 == num2 || num2 == num3 || num1 == num3) {
        printf("Numbers must be different.\n");
        return 1;
    }

    largest = num1;
    if (num2 > largest) largest = num2;
    if (num3 > largest) largest = num3;

    printf("The largest number is %d.\n", largest);

    return 0;
}

