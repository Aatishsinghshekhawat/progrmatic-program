#include <stdio.h>

int main() {
    int array[5] = {3, 17, 80, 202}; 
    int size = 4;
    int value = 75;
    int pos = 0;

    for (int i = 0; i < size; i++) {
        if (value < array[i]) {
            pos = i;
            break;
        } else {
            pos = size;
        }
    }

    for (int i = size; i > pos; i--) {
        array[i] = array[i - 1];
    }

    array[pos] = value;
    size++;

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
