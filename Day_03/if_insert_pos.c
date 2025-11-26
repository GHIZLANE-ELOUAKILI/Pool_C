#include <stdio.h>

int if_insert_pos(int arr[], int size, int n) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            return i; 
        }
        if (arr[i] > n) {
            return i; 
        }
    }
    return size; 
} 

int main() {
    int arr[] = {1, 3, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 4;
    int pos = if_insert_pos(arr, size, n);
    printf("Position d'insertion ou index trouve: %d\n", pos);
    return 0;
}