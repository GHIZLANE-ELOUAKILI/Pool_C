#include <stdio.h>

void f_tableau_multi(int n) {
    for (int i = 0; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

int main() {
    int nombre;
    printf("Entrez un entier pour afficher sa table de multiplication : ");
    scanf("%d", &nombre);
    f_tableau_multi(nombre);
    return 0;
}