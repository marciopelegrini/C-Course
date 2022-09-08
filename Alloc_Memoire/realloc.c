#include <stdio.h>
#include <stdlib.h>

// Alocation de mémoire. avec matrice bi-dimensionnel

int main()
{
    int *p, lignes = 3, collones = 3;

    p = (int*)malloc(lignes * collones * sizeof(int));

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < collones; j++) {
            p[i * collones + j] = 3 * i + j;
        }
    }

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < collones; j++) {
            printf("%d\n", p[i * collones + j]);
        }
    }

    // Liberer la mémoire
    free(p);
    p = NULL;

    return 0;
}