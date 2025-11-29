#include <stdbool.h>

bool is_powerof3(int n) {
    if (n < 1) return false; // Les puissances de 3 sont toujours positives
    while (n % 3 == 0) {
        n /= 3; // Diviser par 3 tant que c'est possible
    }
    return n == 1; // Si on arrive à 1, c'est une puissance de 3
}