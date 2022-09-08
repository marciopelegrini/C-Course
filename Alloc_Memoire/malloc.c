#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quantite, *p;

    printf("Tapez la quantité de numeros que tu veut entrer : ");
    scanf("%d", &quantite);

    p = (int*)malloc(quantite * sizeof(int));

    if (p) {
        for (int i = 0; i < quantite; i++) {
            printf("Tapez le valeur pour la position %d du vector : ", (i + 1));
            scanf("%d", &p[i]);
        }

        for (int i = 0; i < quantite; i++) {
            printf("Dans le vector 'numeros[%d]' a le valeur %d.\n", i, p[i]);
        }

        printf("L'array 'p' prendre %ld bytes de mémoire.\n", quantite * sizeof(int));
    } else {
        printf("Mémoire insufissant !");
    }

    // Liberer la mémoire
    free(p);
    p = NULL;

    return 0;
}