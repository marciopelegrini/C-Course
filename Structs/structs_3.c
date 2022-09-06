#include <stdio.h>
#include <string.h>

struct st_contact
{
    char nom[100];
    int annee_naissance;
    char phone[20];
    char email[100];
};

struct st_agenda
{
    struct st_contact contacts[100];
} agenda;

int main()
{
    // struct st_eleve eleves[5];

    for (int i = 0; i < 3; i++)
    {
        printf("Le nom du contact       : ");
        fgets(agenda.contacts[i].nom, 100, stdin);

        printf("L'année de naissance    : ");
        scanf("%d", &agenda.contacts[i].annee_naissance);
        getchar();

        printf("Le téléphone du contact : ");
        fgets(agenda.contacts[i].phone, 20, stdin);

        printf("Le courriel du contact  : ");
        fgets(agenda.contacts[i].email, 100, stdin);

        printf("-------------------------------------\n");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("================== Agenda des contacts =======================\n");
        printf("=================== Contact %d ===============================\n", (i + 1));
        printf("Nom       : %s\n", strtok(agenda.contacts[i].nom, "\n"));
        printf("Année nasc: %d\n", agenda.contacts[i].annee_naissance);
        printf("Téléphone : %s\n", strtok(agenda.contacts[i].phone, "\n"));
        printf("Courriel  : %s\n", strtok(agenda.contacts[i].email, "\n"));
    }
    return 0;
}