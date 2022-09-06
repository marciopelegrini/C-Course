#include <stdio.h>

int main()
{
    FILE* fichier;
    char c;
    // fopen(nom du fichier, façon de l'ouvrir)
    // w -> ouvrir pour écrire
    // r -> ouvrir pour lire pas écrire
    // wa -> ouvrir pour ajouter contenu
    fichier = fopen("fichier.txt", "r");

    if (fichier) {
        while ((c = getc(fichier)) != EOF) {
            printf("%c", c);
        }
    } else {
        printf("Le fichier n'a pas été touvé\n");
    }

    // Il faut toujours fermer le fichier
    fclose(fichier);

    return 0;
}