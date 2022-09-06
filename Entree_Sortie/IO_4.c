#include <stdio.h>

int main()
{
    FILE* fichier;
    char fruit[10];
    // Avec 'w' si le fichier existe, les données seront perdus.
    fichier = fopen("fruits.txt", "w");

    if (fichier) {
        printf("Tapez une fruit ou 0 to quitter le programme.\n");
        fgets(fruit, 10, stdin); // entrée par default
        while (fruit[0] != '0') {
            fputs(fruit, fichier);
            printf("Tapez une fruit ou 0 to quitter le programme.\n");
            fgets(fruit, 10, stdin); // entrée par default
        }
    } else {
        printf("Impossible de créér le fichier\n");
    }

    // Il faut toujours fermer le fichier
    fclose(fichier);
    return 0;
}