#include <stdio.h>
#include <time.h>

int main() {
    int age, retire, year;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    year = tm.tm_year + 1900;
    
    printf("What is your current age? ");
    scanf("%d", &age);
    printf("At what age would you like to retire? ");
    scanf("%d", &retire);
    
    printf("You have %d years left until you can retire.\n", retire - age);
    printf("It's %d, so you can retire in %d.\n", year, year + (retire - age));
    return 0;
}

