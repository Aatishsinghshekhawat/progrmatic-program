#include <stdio.h>

int main() {
    char response;

    printf("Is the car silent when you turn the key? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        printf("Are the battery terminals corroded? (y/n): ");
        scanf(" %c", &response);

        if (response == 'y' || response == 'Y')
            printf("Clean terminals and try starting again.\n");
        else
            printf("Replace cables and try again.\n");
    } else {
        printf("Does the car make a clicking noise? (y/n): ");
        scanf(" %c", &response);

        if (response == 'y' || response == 'Y')
            printf("Replace the battery.\n");
        else
            printf("Does the car crank up but fail to start? (y/n): ");
            scanf(" %c", &response);
        
        if (response == 'y' || response == 'Y')
            printf("Check spark plug connections.\n");
        else
            printf("Get the car serviced.\n");
    }

    return 0;
}

