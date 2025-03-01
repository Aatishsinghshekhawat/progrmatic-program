#include <stdio.h>

int main() {
    int age;
    const int driving_age = 16;

    printf("What is your age? ");
    scanf("%d", &age);

    printf("You are %s to legally drive.\n", (age >= driving_age) ? "old enough" : "not old enough");

    return 0;
}

