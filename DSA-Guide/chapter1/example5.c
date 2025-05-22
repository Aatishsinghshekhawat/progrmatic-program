#include <stdio.h>

int main() {
    const char *array[5] = {"apples", "bananas", "cucumbers", "dates", "elderberries"};
    int size = 5;
    int index = 2;

    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;

    for (int i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }

    return 0;
}
