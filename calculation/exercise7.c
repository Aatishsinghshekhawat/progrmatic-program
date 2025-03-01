#include <stdio.h>

int main() {
    float length, width, area_feet, area_meters;
    const float conversion_factor = 0.09290304;

    printf("What is the length of the room in feet? ");
    scanf("%f", &length);
    printf("What is the width of the room in feet? ");
    scanf("%f", &width);

    area_feet = length * width;
    area_meters = area_feet * conversion_factor;

    printf("You entered dimensions of %.2f feet by %.2f feet.\n", length, width);
    printf("The area is %.2f square feet (%.3f square meters).\n", area_feet, area_meters);

    return 0;
}

