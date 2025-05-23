#include <stdio.h>

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];  
        int j = i - 1;

      
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

int main() {
    int arr[] = {4, 2, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
