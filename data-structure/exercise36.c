#include <stdio.h>
#include <math.h>

int main() {
    double numbers[10], sum = 0, mean, variance = 0, stddev;
    int count = 0;
    char input[20];

    while (1) {
        printf("Enter a number (or type 'done'): ");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) break;
        numbers[count++] = atof(input);
        sum += numbers[count - 1];
    }

    mean = sum / count;
    for (int i = 0; i < count; i++)
        variance += pow(numbers[i] - mean, 2);

    stddev = sqrt(variance / count);

    printf("Mean: %.2f\nMin: %.2f\nMax: %.2f\nStandard Deviation: %.2f\n", mean, numbers[0], numbers[count - 1], stddev);
    return 0;
}
