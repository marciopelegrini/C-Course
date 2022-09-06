#include <stdio.h>
#include <string.h>

struct st_eleve
{
    char matricule[10];
    char nom[100];
    char cours[50];
    int annee_naissance;
};

int main()
{
    struct st_eleve eleve1;

    printf("La matricule du elève : ");
    fgets(eleve1.matricule, 10, stdin);

    printf("Le nom du elève : ");
    fgets(eleve1.nom, 100, stdin);

    printf("Le cours du elève : ");
    fgets(eleve1.cours, 50, stdin);

    printf("L'année des naissance du elève : ");
    scanf("%d", &eleve1.annee_naissance);

    printf("==================Données du elève==============================\n");
    printf("Matricule : %s\n", eleve1.matricule);
    printf("Nom       : %s\n", eleve1.nom);
    printf("Cours     : %s\n", eleve1.cours);
    printf("Année nasc: %d\n", eleve1.annee_naissance);
    printf("================================================================\n");

    return 0;
}