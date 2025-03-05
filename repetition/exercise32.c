#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int level, range, target, guess, attempts = 0;
    
    printf("Let's play Guess the Number. \n");

    printf("Choose difficulty (1 = 1-10, 2 = 1-100, 3 = 1-1000): ");
    scanf("%d", &level);

    range = (level == 1) ? 10 : (level == 2) ? 100 : 1000;

    srand(time(0));  
    target = rand() % range + 1;  
    
    printf("I have my number. What's your guess? ");

    do {
        scanf("%d", &guess);
        attempts++;

        if (guess < target)
            printf("Too low. Try again: ");
        else if (guess > target)
            printf("Too high. Try again: ");
    } while (guess != target);
    printf("You got it in %d attempts!\n", attempts);
    return 0;
}

