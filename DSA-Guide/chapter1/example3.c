#include <stdio.h>
#include <string.h>

int main() {
    const char *array[6] = {"apples", "bananas", "cucumbers", "dates", "elderberries"};
    int size = 5;

    array[size++] = "mango";
    for (int i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }

    return 0;
}
