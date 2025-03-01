#include <stdio.h>
#include <string.h>

int main() {
    char password[20];
    const char correct_password[] = "abc$123";

    printf("What is the password? ");
    scanf("%s", password);

    if (strcmp(password, correct_password) == 0)
        printf("Welcome!\n");
    else
        printf("I don't know you.\n");

    return 0;
}

