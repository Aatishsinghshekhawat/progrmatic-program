#include<stdio.h>
#include<string.h>

int main(){

    char employee[5][30] = {"John Smith","Jackie Jackson","Chris Jones","Amanda Cullen","Jeremy Goodwin"};
    int  i,j,total = 5;
    char name[30];

    printf("There are 5 employees: \n");
    for ( i = 0; i < total; i++)
    {
        printf("%s \n", employee[i]);
    }
     printf("Enter the employee name to remove: \n");
     fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (i = 0; i < total; i++) {
        if (strcmp(employee[i], name) == 0) {
            for (j = i; j < total - 1; j++)
                strcpy(employee[j], employee[j + 1]);
            total--;
            break;
        }
    }

    printf("\nThere are %d employees:\n", total);
    for ( i = 0; i < total; i++)
    {
        printf("%s\n", employee[i]);
    }
    

    return 0;
}