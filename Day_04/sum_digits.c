#include <stdio.h>

int sum_digits(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        int temp = i;
        while (temp > 0) {
            sum += temp % 10; 
            temp /= 10;      
        }
    }
    return sum;
}

int main() {
    int n = 10; 
    printf("La somme des chiffres de 0 à %d est : %d\n", n, sum_digits(n));
    return 0;
}