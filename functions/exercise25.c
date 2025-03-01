#include <stdio.h>
#include <string.h>
#include <ctype.h>

int passStrength(const char *pass) {
    int Letter = 0, Digit = 0, Special = 0, length = strlen(pass);

    for (int i = 0; pass[i] != '\0'; i++) {
        if (isalpha(pass[i])) Letter = 1;
        else if (isdigit(pass[i])) Digit = 1;
        else Special = 1;
    }

    if (length < 8) return hasDigit ? 1 : 2;
    return Letter && Digit && Special ? 4 : 3;
}

int main() {
    char pass[100];

    printf("Enter a password: ");
    scanf("%s", pass);

    switch (passStrength(pass)) {
        case 1: printf("Very weak password.\n"); break;
        case 2: printf("Weak password.\n"); break;
        case 3: printf("Strong password.\n"); break;
        case 4: printf("Very strong password.\n"); break;
    }

    return 0;
}

