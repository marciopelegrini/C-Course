#include <stdio.h>

int main()
{
    int numero, somme = 0;

    for (int i = 0; i < 5; i++) {
        // Entrée des données
        printf("Veuillez entrer un numéro : ");
        scanf("%d", &numero);

        // Process
        somme = somme + numero;
    }
    // Sortie
    printf("La somme est : %d\n", somme);

    return 0;
}