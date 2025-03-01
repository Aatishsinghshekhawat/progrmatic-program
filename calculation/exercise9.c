#include <stdio.h>
#include <math.h>

int main() {
    float length, width, area;
    const int coverage_per_gallon = 350;
    
    printf("Enter length of the room in feet: ");
    scanf("%f", &length);
    printf("Enter width of the room in feet: ");
    scanf("%f", &width);

    area = length * width;
    int gallons = ceil(area / coverage_per_gallon);

    printf("You will need to purchase %d gallons of paint to cover %.2f square feet.\n", gallons, area);

    return 0;
}

