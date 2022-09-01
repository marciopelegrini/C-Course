#include <stdio.h>
// Type des données

// Types alpha numériques

// String = "  "

int main()
{
    char nom[50];

    printf("Veuillez taper ton nom: \n");

    gets(nom);

    printf("Ton nom est: %s", nom);

    return 0;
}