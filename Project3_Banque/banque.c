#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Si tu est sur Linux/Mac sleep()
//#include <windows.h> //Si tu est sur Windows Sleep(seg)
#include <time.h>

typedef struct {
    int code;
    char nom[50];
    char email[50];
    char nas[20];
    char dateNaissance[20];
    char dateEnregistrement[20];
} Client;

typedef struct {
    int numero;
    Client client;
    float solde;
    float limite;
    float soldeTotal; // solde + limite
} Compte;

void menu();
void infoClient(Client client);
void infoCompte(Compte compte);
void creerCompte();
void effectuerRetrait();
void effectuerDepot();
void effectuerTransfer();
void listerComptes();
float majSoldeTotal(Compte compte);
Compte chercherCompteParNumero(int numero);
void retrait(Compte compte, float valeur);
void depot(Compte compte, float valeur);
void transfer(Compte compte_origine, Compte compte_destine, float valeur);

static Compte comptes[50];
static int compteur_compte = 0;
static int compteur_clients = 0;

int main()
{
    menu();
    return 0;
}

void menu()
{
    sleep(2);
    int option = 0;

    printf("======================================\n");
    printf("=============== ATM ==================\n");
    printf("============= Geek Bank ==============\n");
    printf("======================================\n");

    printf("Séléctionner une option au menu:\n");
    printf("1 - Créér compte\n");
    printf("2 - Effectuer retrait\n");
    printf("3 - Effectuer depôt\n");
    printf("4 - Effectuer transfer\n");
    printf("5 - Lister comptes\n");
    printf("6 - Quitter le système\n");

    scanf("%d", &option);
    getchar();

    switch (option) {
    case 1:
        creerCompte();
        break;
    case 2:
        effectuerRetrait();
        break;
    case 3:
        effectuerDepot();
        break;
    case 4:
        effectuerTransfer();
        break;
    case 5:
        listerComptes();
        break;
    case 6:
        printf("À bientôt!\n");
        sleep(2); // Sleep(2)
        exit(0);
    default:
        printf("Option invalide.\n");
        menu();
        break;
    }
}

void infoClient(Client client)
{
    printf("Code: %d \nnom: %s \nDate de naissance: %s \nEnregistrement: %s\n",
        client.code, strtok(client.nom, "\n"), strtok(client.dateNaissance, "\n"),
        strtok(client.dateEnregistrement, "\n"));
}

void infoCompte(Compte compte)
{
    printf("Numéro du compte: %d \nClient: %s \nDate de naissance: %s \nDate d'enregistrement: %s \nSolde Total: %.2f\n",
        compte.numero, strtok(compte.client.nom, "\n"), strtok(compte.client.dateNaissance, "\n"),
        strtok(compte.client.dateEnregistrement, "\n"), compte.soldeTotal);
}

void creerCompte()
{
    Client client;

    // Date d'enregistrement
    char jour[3]; // 06\0
    char mois[3]; // 08
    char annee[5]; // 2020
    char date_enregistrement[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // jour
    if (tm.tm_mday < 10) {
        sprintf(jour, "0%d", tm.tm_mday); // 1, 2, 3, 4, 5, 6, 7, 8, 9 -> 01/08/2020
    } else {
        sprintf(jour, "%d", tm.tm_mday);
    }

    // mois
    if ((tm.tm_mon + 1) < 10) { // 01/08/2020
        sprintf(mois, "0%d", tm.tm_mon + 1);
    } else {
        sprintf(mois, "%d", tm.tm_mon + 1);
    }

    // annee
    sprintf(annee, "%d", tm.tm_year + 1900);

    strcpy(date_enregistrement, "");
    strcat(date_enregistrement, jour); // 22
    strcat(date_enregistrement, "/"); // 22/
    strcat(date_enregistrement, mois); // 22/08
    strcat(date_enregistrement, "/"); // 22/08/
    strcat(date_enregistrement, annee); // 22/08/2020
    strcat(date_enregistrement, "\0");
    strcpy(client.dateEnregistrement, date_enregistrement);

    // Creer o client
    printf("Veuillez tapez le infos du client:\n");
    client.code = compteur_clients + 1;

    printf("Nom du client: \n");
    fgets(client.nom, 50, stdin);

    printf("E-mail du client: \n");
    fgets(client.email, 50, stdin);

    printf("NAS du client: \n");
    fgets(client.nas, 20, stdin);

    printf("Date de naissance du client: \n");
    fgets(client.dateNaissance, 20, stdin);

    compteur_clients++;

    // Creer le compte
    comptes[compteur_compte].numero = compteur_compte + 1;
    comptes[compteur_compte].client = client;
    comptes[compteur_compte].solde = 0.0;
    comptes[compteur_compte].limite = 0.0;
    comptes[compteur_compte].soldeTotal = majSoldeTotal(comptes[compteur_compte]);

    printf("Compte créé avec sucèss!\n");
    printf("\n");
    printf("Données du compte créé: \n");
    printf("\n");
    infoCompte(comptes[compteur_compte]);
    compteur_compte++;

    sleep(2);
    menu();
}

float majSoldeTotal(Compte compte)
{
    return compte.solde + compte.limite;
}

Compte chercherCompteParNumero(int numero)
{
    Compte c;
    if (compteur_compte > 0) {
        for (int i = 0; i < compteur_compte; i++) {
            if (comptes[i].numero == numero) {
                c = comptes[i];
            }
        }
    }
    return c;
}

void retrait(Compte compte, float valeur)
{
    if (valeur > 0 && compte.soldeTotal >= valeur) {
        for (int i = 0; i < compteur_compte; i++) {
            if (comptes[i].numero == compte.numero) {
                if (comptes[i].solde >= valeur) {
                    comptes[i].solde = comptes[i].solde - valeur;
                    comptes[i].soldeTotal = majSoldeTotal(comptes[i]);
                    printf("Retrait fait avec sucèss\n");
                } else {
                    float restant = comptes[i].solde - valeur;
                    comptes[i].limite = comptes[i].limite + restant;
                    comptes[i].solde = 0.0;
                    comptes[i].soldeTotal = majSoldeTotal(comptes[i]);
                    printf("Retrait fait avec sucèss\n");
                }
            }
        }
    } else {
        printf("Le retrait n'ai été pas réalisé. Veuillez réesayer.\n");
    }
}

void depot(Compte compte, float valeur)
{
    if (valeur > 0) {
        for (int i = 0; i < compteur_compte; i++) {
            if (comptes[i].numero == compte.numero) {
                comptes[i].solde = comptes[i].solde + valeur;
                comptes[i].soldeTotal = majSoldeTotal(comptes[i]);
                printf("Depôt fait avec sucèss\n");
            }
        }
    } else {
        printf("Erreur en fait le depôt. Veuillez réesayer.\n");
    }
}

void transfer(Compte compte_origine, Compte compte_destine, float valeur)
{
    if (valeur > 0 && compte_origine.soldeTotal >= valeur) {
        for (int co = 0; co < compteur_compte; co++) {
            if (comptes[co].numero == compte_origine.numero) {
                for (int cd = 0; cd < compteur_compte; cd++) {
                    if (comptes[cd].numero == compte_destine.numero) {
                        if (comptes[co].solde >= valeur) {
                            comptes[co].solde = comptes[co].solde - valeur;
                            comptes[cd].solde = comptes[cd].solde + valeur;
                            comptes[co].soldeTotal = majSoldeTotal(comptes[co]);
                            comptes[cd].soldeTotal = majSoldeTotal(comptes[cd]);
                            printf("Le transfer a bien été fait.\n");
                        } else {
                            float restant = comptes[co].solde - valeur;
                            comptes[co].limite = comptes[co].limite + restant;
                            comptes[co].solde = 0.0;
                            comptes[cd].solde = comptes[cd].solde + valeur;
                            comptes[co].soldeTotal = majSoldeTotal(comptes[co]);
                            comptes[cd].soldeTotal = majSoldeTotal(comptes[cd]);
                            printf("Le transfer a bien été fait.\n");
                        }
                    }
                }
            }
        }
    } else {
        printf("Le transfer n'ai pas été fait. Veuillez réesayer.\n");
    }
}

void effectuerRetrait()
{
    if (compteur_compte > 0) {
        int numero;
        printf("Tapez le numéro du compte: \n");
        scanf("%d", &numero);

        Compte compte = chercherCompteParNumero(numero);

        if (compte.numero == numero) {
            float valeur;
            printf("Tapez le valeur du retrait: \n");
            scanf("%f", &valeur);

            retrait(compte, valeur);
        } else {
            printf("Le compte %d n'ai été pas trouvé.\n", numero);
        }

    } else {
        printf("Il n'y a pas des comptes pour faire retraits.\n");
    }
    menu();
}

void effectuerDepot()
{
    if (compteur_compte > 0) {
        int numero;
        printf("Tapex le numéro du compte :  \n");
        scanf("%d", &numero);

        Compte compte = chercherCompteParNumero(numero);

        if (compte.numero == numero) {
            float valeur;
            printf("Tapez o valeur do depôt: \n");
            scanf("%f", &valeur);

            depot(compte, valeur);
        } else {
            printf("Não foi encontrada uma compte com o numéro %d\n", numero);
        }

    } else {
        printf("Ainda não existem comptes para depôt.\n");
    }
    menu();
}

void effectuerTransfer()
{
    if (compteur_compte > 0) {
        int numero_o, numero_d;
        printf("Tapez le numéro de votre compte: \n");
        scanf("%d", &numero_o);

        Compte compte_o = chercherCompteParNumero(numero_o);

        if (compte_o.numero == numero_o) {
            printf("Tapez le numéro du compte destine: \n");
            scanf("%d", &numero_d);

            Compte compte_d = chercherCompteParNumero(numero_d);

            if (compte_d.numero == numero_d) {
                float valeur;
                printf("Tapez le valeur pour le transfer: \n");
                scanf("%f", &valeur);

                transfer(compte_o, compte_d, valeur);
            } else {
                printf("Le compte destine numéro %d n'ai été pas trouvé.\n", numero_d);
            }
        } else {
            printf("Le compte numéro %d n'ai pas été trouvé.\n", numero_o);
        }

    } else {
        printf("Il n'y a pas encore de comptes pour le transfer.\n");
    }
    menu();
}

void listerComptes()
{
    if (compteur_compte > 0) {
        for (int i = 0; i < compteur_compte; i++) {
            infoCompte(comptes[i]);
            printf("\n");
            sleep(1);
        }
    } else {
        printf("Il n'y a pas de comptes enregistrés encore.\n");
    }
    menu();
}
