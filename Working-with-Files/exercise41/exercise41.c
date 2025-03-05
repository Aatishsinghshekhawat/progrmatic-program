#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 30  
#define MAX_LENGTH 30 

int main() {
    FILE *file;
    char names[MAX_NAMES][MAX_LENGTH];
    int count = 0;
    

    file = fopen("names.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open names.txt\n");
        return 1;
    }


    while (fgets(names[count], MAX_LENGTH, file)) {
        names[count][strcspn(names[count], "\n")] = '\0';
        count++;
    }
    fclose(file);

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char temp[MAX_LENGTH];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }



    file = fopen("sorted_names.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open sorted_names.txt\n");
        return 1;
    }

    fprintf(file, "Total of %d names\n-----------------\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", names[i]);
    }
    fclose(file);

    printf("Sorted names saved in 'sorted_names.txt'\n");

    return 0;
}
