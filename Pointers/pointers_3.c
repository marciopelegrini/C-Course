#include <stdio.h>

int main()
{
    int n;

    int* p; //pointer c'est une valeur dans l'adresse de mémoire.

    printf("Tapez un numéro: ");
    scanf("%d", &n);

    p = &n;

    printf("Le numéro tapé est : %d\n", n);
    printf("L'adresse de mémoire est : %p\n", &n);
    printf("L'adresse du pointer est : %p\n", p);

    return 0;
}