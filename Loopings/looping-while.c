#include <stdio.h>

int main()
{
    int numero, somme = 0;

    // Entrée des données
    printf("Veuillez entrer un numéro : ");
    scanf("%d", &numero);

    while (numero != 0) {
        somme = somme + numero;
        
        // Entrée des données
        printf("Veuillez entrer un numéro : ");
        scanf("%d", &numero);
    }

    // Sortie
    printf("La somme est : %d\n", somme);

    return 0;
}