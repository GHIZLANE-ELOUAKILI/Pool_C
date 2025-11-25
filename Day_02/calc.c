#include <stdio.h>

void calc(void) {
    char operation;
    float num1, num2, result;

    printf("Entrez l'operation (+, -, *, /) : ");
    scanf(" %c", &operation);
    
    printf("Entrez le premier nombre : ");
    scanf("%f", &num1);
    
    printf("Entrez le deuxième nombre : ");
    scanf("%f", &num2);

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Erreur : Division par zéro.\n");
                return;
            }
            break;
        default:
            printf("Opération invalide.\n");
            return;
    }

    printf("Le résultat est : %.2f\n", result);
}

int main() {
    calc();
    return 0;
}