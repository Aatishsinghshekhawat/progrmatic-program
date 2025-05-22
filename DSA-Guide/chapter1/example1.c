#include <stdio.h>
#include <string.h>

int main() {
    char x[] = "Hello! ";
    char y[] = "How are you ";
    char z[] = "today?";
    char result[100];

    strcpy(result, x);
    strcat(result, y);
    strcat(result, z);

    printf("%s\n", result);
    return 0;
}
