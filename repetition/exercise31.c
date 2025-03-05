#include <stdio.h>

int main() {
    int age, restingHR;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your resting heart rate: ");
    scanf("%d", &restingHR);

    printf("Intensity | Heart Rate\n");
    printf("----------------------\n");

    for (int intensity = 55; intensity <= 95; intensity += 5) {
        int targetHR = (((220 - age) - restingHR) * intensity / 100) + restingHR;
        printf("%d%%     | %d bpm\n", intensity, targetHR);
    }

    return 0;
}
