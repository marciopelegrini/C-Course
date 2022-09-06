#include <stdio.h>
#include <string.h>

struct st_eleve
{
    char matricule[10];
    char nom[100];
    char cours[50];
    int annee_naissance;
} eleves[5];

int main()
{
    // struct st_eleve eleves[5];

    for (int i = 0; i < 5; i++)
    {
        printf("La matricule du elève : ");
        fgets(eleves[i].matricule, 10, stdin);

        printf("Le nom du elève       : ");
        fgets(eleves[i].nom, 100, stdin);

        printf("Le cours du elève     : ");
        fgets(eleves[i].cours, 50, stdin);

        printf("L'année des naissance du elève : ");
        scanf("%d", &eleves[i].annee_naissance);
        getchar();
        printf("-------------------------------------\n");
    }

    for (int i = 0; i < 5; i++)
    {
        printf("==================Données du elève %d=======================\n",(i+1));
        printf("Matricule : %s\n", eleves[i].matricule);
        printf("Nom       : %s\n", eleves[i].nom);
        printf("Cours     : %s\n", eleves[i].cours);
        printf("Année nasc: %d\n", eleves[i].annee_naissance);
    }
    return 0;
}