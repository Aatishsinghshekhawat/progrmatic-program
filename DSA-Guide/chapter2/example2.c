#include <stdio.h>

int main() {
    int array[] = {3, 17, 80, 202};
    int size = 4;
    int target = 80;
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
        if (array[i] > target) {
            break;
        }
    }

    if (!found) {
        printf("Not found\n");
    }

    return 0;
}
