#include <stdio.h>

int main() {
    const char *array[] = {"apples", "bananas", "cucumbers", "dates", "elderberries"};
    for (int i = 0; i < 5; i++) {
        printf("Item %d: %s\n", i, array[i]);
    }
    return 0;
}
