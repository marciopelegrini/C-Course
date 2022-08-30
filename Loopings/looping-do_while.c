#include <stdio.h>

int main()
{
    int numero, somme = 0;

    do {
        // Entrée des données
        printf("Veuillez entrer un numéro : ");
        scanf("%d", &numero);
        
        somme = somme + numero;
    } while (numero != 0);

    // Sortie
    printf("La somme est : %d\n", somme);

    return 0;
}