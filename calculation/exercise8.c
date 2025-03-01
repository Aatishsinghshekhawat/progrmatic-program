#include <stdio.h>

int main() {
    int people, pizzas, slices_per_pizza, tslices, slices_each, leftovers;

    printf("How many people? ");
    scanf("%d", &people);
    printf("How many pizzas do you have? ");
    scanf("%d", &pizzas);
    printf("How many slices per pizza? ");
    scanf("%d", &slices_per_pizza);

    tslices = pizzas * slices_per_pizza;
    slices_each = tslices / people;
    leftovers = tslices % people;

    printf("%d people with %d pizzas.\n", people, pizzas);
    printf("Each person gets %d pieces of pizza.\n", slices_each);
    printf("There are %d leftover pieces.\n", leftovers);

    return 0;
}
