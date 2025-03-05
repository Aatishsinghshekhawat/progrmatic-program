#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filterEvenNumbers(int *numbers, int size) {
    printf("The even numbers are:");
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0)
            printf(" %d", numbers[i]);
    }
    printf("\n");
}

int main() {
    char input[100];
    int numbers[20], count = 0;

    printf("Enter a list of numbers, separated by spaces: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while (token != NULL) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ");
    }

    filterEvenNumbers(numbers, count);
    return 0;
}
