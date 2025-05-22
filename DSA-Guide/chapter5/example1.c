#include <stdio.h>

void selectionSort(int array[], int length) {
    for (int i = 0; i < length; i++) {
        int lowestNumberIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[lowestNumberIndex]) {
                lowestNumberIndex = j;
            }
        }

        if (lowestNumberIndex != i) {
            int temp = array[i];
            array[i] = array[lowestNumberIndex];
            array[lowestNumberIndex] = temp;
        }
    }
}

int main() {
    int array[] = {29, 10, 14, 37, 13};
    int length = sizeof(array) / sizeof(array[0]);

    selectionSort(array, length);

    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
