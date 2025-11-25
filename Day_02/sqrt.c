#include <stdio.h>

int sqrt_x(int nb) {
    if (nb < 0) return -1; 
    int i = 0;
    while (i * i <= nb) {
        i++;
    }
    return i - 1; 
}

int main() {
    int num = 16;
    printf("La racine carree de %d est %d\n", num ,sqrt_x(num));
    return 0;
}