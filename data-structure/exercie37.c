#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char getRandomChar(char *set) {
    return set[rand() % strlen(set)];
}

int main() {
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char specials[] = "!@#$%%^&*";
    int length, numSpecials, numNumbers;
    char password[50] = "";

    printf("Minimum length? ");
    if (scanf("%d", &length) != 1) return 1;
    while (getchar() != '\n');

    printf("How many Special characters? ");
    if (scanf("%d", &numSpecials) != 1) return 1;
    while (getchar() != '\n');

    printf("How Many Numbers? ");
    if (scanf("%d", &numNumbers) != 1) return 1;
    while (getchar() != '\n');

    srand(time(0));

    for (int i = 0; i < numSpecials; i++)
        password[i] = getRandomChar(specials);
    for (int i = numSpecials; i < numSpecials + numNumbers; i++)
        password[i] = getRandomChar(numbers);
    for (int i = numSpecials + numNumbers; i < length; i++)
        password[i] = getRandomChar(letters);

    password[length] = '\0';
    printf("Your password is: %s\n", password);
    return 0;
}
