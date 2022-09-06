#include <stdio.h>

// Prototype des fonctions
// Signature des fonctions
int somme(int n1, int n2);

int main()
{
    int n1, n2, retour;

    printf("Tapez le 1er. numéro : ");
    scanf("%d", &n1);

    printf("Tapez le 2ème. numéro : ");
    scanf("%d", &n2);

    printf("La somme est: %d\n", somme(n1, n2));

    return 0;
}

int somme(int num1, int num2)
{
    return num1 + num2;
}