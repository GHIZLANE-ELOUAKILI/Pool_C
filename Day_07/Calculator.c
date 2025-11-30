#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_HISTORY 5
#define MAX_STRING 100

// Structure pour stocker l'historique
typedef struct {
    char calculations[MAX_HISTORY][MAX_STRING];
    int count;
    int current_index;
} History;

// Prototypes des fonctions
void print_menu(void);
void clear_screen(void);
void add_to_history(History *hist, const char *operation, double result);
void show_history(History *hist);
double get_number(const char *prompt);
int get_choice(void);
void wait_for_enter(void);

// Opérations de base
double add(History *hist, double a, double b);
double subtract(History *hist, double a, double b);
double multiply(History *hist, double a, double b);
double divide_numbers(History *hist, double a, double b);

// Opérations avancées
double factorial(History *hist, int n);
double square_root(History *hist, double n);
double power2(History *hist, double n);
double power3(History *hist, double n);

int main(void) {
    History hist;
    hist.count = 0;
    hist.current_index = 0;
    
    int choice;
    double a, b, result;
    int n;
    
    while (1) {
        clear_screen();
        print_menu();
        choice = get_choice();
        
        switch (choice) {
            case 0:
                printf("\n👋 Merci d'avoir utilisé la calculatrice! Au revoir!\n");
                return 0;
            
            case 1:
                a = get_number("Entrez le premier nombre: ");
                b = get_number("Entrez le deuxieme nombre: ");
                result = add(&hist, a, b);
                printf("\n✅ Resultat: %.2f + %.2f = %.2f\n", a, b, result);
                break;
            
            case 2:
                a = get_number("Entrez le premier nombre: ");
                b = get_number("Entrez le deuxieme nombre: ");
                result = subtract(&hist, a, b);
                printf("\n✅ Resultat: %.2f - %.2f = %.2f\n", a, b, result);
                break;
            
            case 3:
                a = get_number("Entrez le premier nombre: ");
                b = get_number("Entrez le deuxieme nombre: ");
                result = multiply(&hist, a, b);
                printf("\n✅ Resultat: %.2f × %.2f = %.2f\n", a, b, result);
                break;
            
            case 4:
                a = get_number("Entrez le premier nombre: ");
                b = get_number("Entrez le deuxieme nombre: ");
                if (b == 0) {
                    printf("\n❌ Erreur: Division par zero!\n");
                } else {
                    result = divide_numbers(&hist, a, b);
                    printf("\n✅ Resultat: %.2f ÷ %.2f = %.2f\n", a, b, result);
                }
                break;
            
            case 5:
                n = (int)get_number("Entrez un nombre entier: ");
                if (n < 0) {
                    printf("\n❌ Erreur: Factorielle d'un nombre negatif!\n");
                } else if (n > 20) {
                    printf("\n❌ Erreur: Nombre trop grand (max 20)!\n");
                } else {
                    result = factorial(&hist, n);
                    printf("\n✅ Resultat: fact(%d) = %.0f\n", n, result);
                }
                break;
            
            case 6:
                a = get_number("Entrez un nombre: ");
                if (a < 0) {
                    printf("\n❌ Erreur: Racine carree d'un nombre negatif!\n");
                } else {
                    result = square_root(&hist, a);
                    printf("\n✅ Resultat: √%.2f = %.2f\n", a, result);
                }
                break;
            
            case 7:
                a = get_number("Entrez un nombre: ");
                result = power2(&hist, a);
                printf("\n✅ Resultat: (%.2f)² = %.2f\n", a, result);
                break;
            
            case 8:
                a = get_number("Entrez un nombre: ");
                result = power3(&hist, a);
                printf("\n✅ Resultat: (%.2f)³ = %.2f\n", a, result);
                break;
            
            case 9:
                show_history(&hist);
                break;
            
            default:
                printf("\n❌ Choix invalide! Veuillez selectionner 0-9.\n");
        }
        
        wait_for_enter();
    }
    
    return 0;
}

void print_menu(void) {
    printf("\n");
    printf("==================================================\n");
    printf("🔢 CALCULATRICE CLI AVEC HISTORIQUE\n");
    printf("==================================================\n");
    printf("\n📌 OPERATIONS DE BASE:\n");
    printf("  1. Addition :\n");
    printf("  2. Soustraction :\n");
    printf("  3. Multiplication :\n");
    printf("  4. Division :\n");
    printf("\n📌 OPERATIONS AVANCEES:\n");
    printf("  5. Factorielle :\n");
    printf("  6. Racine Carree : \n");
    printf("  7. Puissance 2  : \n");
    printf("  8. Puissance 3 :\n");
    printf("\n📌 AUTRE:\n");
    printf("  9. Afficher l'Historique :\n");
    printf("  0. Quitter :\n");
    printf("==================================================\n");
}

void clear_screen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void add_to_history(History *hist, const char *operation, double result) {
    char entry[MAX_STRING];
    snprintf(entry, MAX_STRING, "%s = %.2f", operation, result);
    
    strcpy(hist->calculations[hist->current_index], entry);
    hist->current_index = (hist->current_index + 1) % MAX_HISTORY;
    
    if (hist->count < MAX_HISTORY) {
        hist->count++;
    }
}

void show_history(History *hist) {
    if (hist->count == 0) {
        printf("\n📝 Aucun historique disponible!\n");
        return;
    }
    
    printf("\n📝 5 Derniers Calculs:\n");
    printf("----------------------------------------\n");
    
    int start_index = hist->current_index - hist->count;
    if (start_index < 0) {
        start_index += MAX_HISTORY;
    }
    
    for (int i = 0; i < hist->count; i++) {
        int index = (start_index + i) % MAX_HISTORY;
        printf("%d. %s\n", i + 1, hist->calculations[index]);
    }
    printf("----------------------------------------\n");
}

double get_number(const char *prompt) {
    char buffer[100];
    double num;
    
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("❌ Erreur de lecture!\n");
            continue;
        }
        
        if (sscanf(buffer, "%lf", &num) == 1) {
            return num;
        }
        
        printf("❌ Entree invalide! Veuillez entrer un nombre valide.\n");
    }
}

int get_choice(void) {
    char buffer[100];
    int choice;
    
    while (1) {
        printf("\n👉 Selectionnez une operation (0-9): ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("❌ Erreur de lecture!\n");
            continue;
        }
        
        if (sscanf(buffer, "%d", &choice) == 1) {
            return choice;
        }
        
        printf("❌ Choix invalide! Veuillez entrer un nombre entre 0 et 9.\n");
    }
}

void wait_for_enter(void) {
    printf("\n⏎ Appuyez sur Entree pour continuer...");
    fflush(stdout);  // Force l'affichage du message
    
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        // Gérer l'erreur ou EOF
        return;
    }
}

// Opérations de base
double add(History *hist, double a, double b) {
    double result = a + b;
    char operation[MAX_STRING];
    snprintf(operation, MAX_STRING, "%.2f + %.2f", a, b);
    add_to_history(hist, operation, result);
    return result;
}

double subtract(History *hist, double a, double b) {
    double result = a - b;
    char operation[MAX_STRING];
    snprintf(operation, MAX_STRING, "%.2f - %.2f", a, b);
    add_to_history(hist, operation, result);
    return result;
}

double multiply(History *hist, double a, double b) {
    double result = a * b;
    char operation[MAX_STRING];
    snprintf(operation, MAX_STRING, "%.2f × %.2f", a, b);
    add_to_history(hist, operation, result);
    return result;
}

double divide_numbers(History *hist, double a, double b) {
    double result = a / b;
    char operation[MAX_STRING];
    snprintf(operation, MAX_STRING, "%.2f ÷ %.2f", a, b);
    add_to_history(hist, operation, result);
    return result;
}

// Opérations avancées
double factorial(History *hist, int n) {
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    char operation[MAX_STRING];
    snprintf(operation, MAX_STRING, "fact(%d)", n);
    add_to_history(hist, operation, result);
    return result;
}

double square_root(History *hist, double n) {
    double result = sqrt(n);
    char operation[MAX_STRING];
    snprintf(operation, MAX_STRING, "√%.2f", n);
    add_to_history(hist, operation, result);
    return result;
}

double power2(History *hist, double n) {
    double result = n * n;
    char operation[MAX_STRING];
    snprintf(operation, MAX_STRING, "(%.2f)²", n);
    add_to_history(hist, operation, result);
    return result;
}

double power3(History *hist, double n) {
    double result = n * n * n;
    char operation[MAX_STRING];
    snprintf(operation, MAX_STRING, "(%.2f)³", n);
    add_to_history(hist, operation, result);
    return result;
}