#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("What is the input string? ");
    scanf("%s", input);
    printf("%s has %lu characters.\n", input, strlen(input));
    return 0;
}

