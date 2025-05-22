#include <stdio.h>

void bubble_sort(int arr[], int length) {
    int unsorted_until_index = length - 1;
    int sorted = 0; 

    while (!sorted) {
        sorted = 1; 
        for (int i = 0; i < unsorted_until_index; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0; 
            }
        }
        unsorted_until_index--;
    }
}

int main() {
    int list[] = {65, 55, 45, 35, 25, 15, 10};
    int length = sizeof(list) / sizeof(list[0]);

    bubble_sort(list, length);

    printf("sorted array \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", list[i]);
    }

    return 0;
}

