#include <stdio.h>
#include <string.h>

int contains(const char *array[], int size, const char *value) {
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i], value) == 0)
            return 1;
    }
    return 0;
}

int main() {
    const char *set[10] = {"apples", "bananas", "cucumbers", "dates", "elderberries"};
    int size = 5;
    const char *newItem = "mango";

    if (!contains(set, size, newItem)) {
        set[size++] = newItem;
    }

    for (int i = 0; i < size; i++) {
        printf("%s\n", set[i]);
    }

    return 0;
}
