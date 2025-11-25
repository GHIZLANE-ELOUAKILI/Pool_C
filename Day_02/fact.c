#include <stdio.h>

int factorial(int nb) {
    if (nb == 0) {
        return 1; 
    } else {
        return nb * factorial(nb - 1); 
    }
}

int main() {
    int num = 5;
    printf("La factorielle de %d est %d\n", num, factorial(num));
    return 0;
}