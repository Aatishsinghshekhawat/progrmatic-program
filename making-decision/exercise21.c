#include <stdio.h>

int main() {
    int month;
    const char *months[] = {
        "Invalid", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Enter the number of the month: ");
    scanf("%d", &month);

    if (month >= 1 && month <= 12)
        printf("The name of the month is %s.\n", months[month]);
    else
        printf("Invalid month number.\n");

    return 0;
}


