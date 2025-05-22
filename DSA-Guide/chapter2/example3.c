#include <stdio.h>

int main() {
    int array[] = {3, 17, 80, 202};
    int size = 4;
    int target = 80;
    int low = 0, high = size - 1;
    int found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (array[mid] == target) {
            printf("Found at index %d\n", mid);
            found = 1;
            break;
        } else if (target < array[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (!found) {
        printf("Not found\n");
    }

    return 0;
}
