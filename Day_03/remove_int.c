#include <stdio.h>

void remove_int(int arr[], int *size, int target) {
    for (int i = 0; i < *size; i++) {
        if (arr[i] == target) {
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--; 
            i--; 
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 3, 5};
    int size = 6;
    int target = 3;

    remove_int(arr, &size, target);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}