#include <stdio.h>

int main()
{
    FILE* fichier;
    int num, result, somme = 0;

    fichier = fopen("fichier2.txt", "r");

    if (fichier) {
        while (!feof(fichier)) {
            result = fscanf(fichier, "%d", &num);
            if (result == 1) {
                somme += num;
            }
        }
    } else {
        printf("Le fichier n'a pas été touvé\n");
    }
    printf("La somme des numéros du fichier est : %d\n", somme);
    // Il faut toujours fermer le fichier
    fclose(fichier);
    return 0;
}