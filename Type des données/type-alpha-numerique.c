#include <stdio.h>
// Type des données

// Types alpha numériques

// String = "  "
// Caract  = 's'

int main()
{
    char option;

    printf("Veuillez choisir une option: \n");
    printf("a - Solde du compte: \n");
    printf("b - Rapport du compte \n");
    scanf("%c", &option);

    if (option == 'a') {
        printf("Option choisi => a ");
    } else if (option == 'b') {
        printf("Option choisi => b ");
    } else {
        printf("Option invalide ");
    }

    return 0;
}