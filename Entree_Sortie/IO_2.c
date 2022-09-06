#include <stdio.h>

int main()
{
    FILE* fichier;
    char nom[10], *result;

    fichier = fopen("fichier.txt", "r");

    if (fichier) {
        while (!feof(fichier)) {
            result = fgets(nom, 10, fichier);
            printf("Result : %d\n", result);
            if (result) {
                printf("%s\n", nom);
            }
        }
    } else {
        printf("Le fichier n'a pas été touvé\n");
    }

    // Il faut toujours fermer le fichier
    fclose(fichier);
    return 0;
}