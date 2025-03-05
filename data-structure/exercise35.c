#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

    char names [10][20];
    int winner,count = 0;
    char name[20];

    while (1) {
        printf("Enter a name (or press Enter to stop): ");
        
        if (fgets(name, sizeof(name), stdin) == NULL){

            break;
        }

        
        name[strcspn(name, "\n")] = '\0';

        if (strlen(name) == 0){

            break;
        }
        strcpy(names[count++], name);

        if (count >= 10) {
            printf("Maximum number of names reached.\n");
            break;
        }
    }

    if (count == 0) {
        printf("No names were entered. Exiting.\n");
        return 0;
    }

    
    srand(time(0));
    winner = rand() % count;
    
    printf("The winner is .. %s \n", names[winner]);


    return 0;
}