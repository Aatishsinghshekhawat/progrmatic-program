#include <stdio.h>

int main() {
    const char *array[6] = {"apples", "bananas", "cucumbers", "dates", "elderberries"};
    int size = 5;
    int index = 2;

    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }

    array[index] = "msngo";
    size++;

    for (int i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }

    return 0;
}