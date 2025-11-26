#include <stdio.h>

void min_max(int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int T[] = {3, 5, 1, 8, 2};
    int min, max;
    min_max(T, 5, &min, &max);
    
    printf("Min: %d, Max: %d\n", min, max);
    return 0;
}