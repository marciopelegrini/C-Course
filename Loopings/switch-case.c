#include <stdio.h>

int main()
{
    int valeur;

    printf("Veuillez entrer un valeur de 1 ou 2 : ");
    scanf("%d", &valeur);

    switch (valeur) {
    case 1:
        printf("Dimanche\n");
        break;
    case 2:
        printf("Lundi\n");
        break;

    default:
        printf("Le valeur est invalide.\n");
    }

    return 0;
}