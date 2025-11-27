#include <stdio.h>

int f_ispowerof2(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

int main() {
    int number = 16; 
    if (f_ispowerof2(number)) {
        printf("%d est une puissance de 2.\n", number);
    } else {
        printf("%d n'est pas une puissance de 2.\n", number);
    }
    return 0;
}