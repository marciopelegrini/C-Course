#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //Linux or Mac
//#include <windows.h> //If Windows

typedef struct {
    int code;
    char nom[30];
    float prix;
} Produit;

typedef struct
{
    Produit produit;
    int quantite;
} Panier;

void infoProduit(Produit prod);
void menu();
void enregistrerProduit();
void acheterProduit();
void listerProduit();
void afficherPanier();
Produit prendreProduitParCode(int code);
int* aDansPanier(int code);
void fermerCommande();

static int compteur_produit = 0;
static int compteur_panier = 0;
static Panier panier[50];
static Produit produits[50];

int main()
{
    menu();
    return 0;
}

void infoProduit(Produit prod)
{
    printf("Code : %d \nNom : %s \nPrix : %.2f\n", prod.code, strtok(prod.nom, "\n"), prod.prix);
}
void menu()
{
    printf("==================================================\n");
    printf("==================== Bienvienu (e) ===============\n");
    printf("==================================================\n");

    printf("Selectionnez une option ci-dessus: \n");
    printf("1 - Enregistrer produit\n");
    printf("2 - Liste de produits\n");
    printf("3 - Acheter produit\n");
    printf("4 - Afficher le panier\n");
    printf("5 - Fermer la commande\n");
    printf("6 - Quitter le système\n");

    int option;
    scanf("%d", &option);
    getchar();

    switch (option) {
    case 1:
        enregistrerProduit();
        break;
    case 2:
        listerProduit();
        break;
    case 3:
        acheterProduit();
        break;
    case 4:
        afficherPanier();
        break;
    case 5:
        fermerCommande();
    case 6:
        printf("À bientôt...\n");
        sleep(2);
        exit(0);
        break;
    default:
        printf("Option invalide.\n");
        sleep(2);
        menu();
        break;
    }
}

void enregistrerProduit()
{
    printf("Entrez le nom du produit : \n");
    fgets(produits[compteur_produit].nom, 30, stdin);

    printf("Entrez le nom du produit : \n");
    scanf("%d", &produits[compteur_produit].prix);

    printf("Le produit a bien été enregistrer.\n", strtok(produits[compteur_produit].nom, "\n"));
    produits[compteur_produit].code = (compteur_produit + 1);
    compteur_produit++;
}
void listerProduit()
{
    if (compteur_produit > 0) {
        printf("Liste des produits.\n");
        printf("-------------------\n");
        for (int i = 0; i < compteur_produit; i++) {
            infoProduit(produits[i]);
            printf("------------------\n");
            sleep(1);
        }

    } else {
        printf("Il n'y a pas de produits enregistrés.\n");
    }
}
void acheterProduit()
{
    // todo
}
void afficherPanier()
{
    if (compteur_panier > 0) {
        printf("Produits dans le panier.\n");
        printf("------------------------\n");
        for (int i = 0; i < compteur_panier; i++) {
            infoProduit(panier[i].produit);
            printf("Quantité : %d\n", panier[i].quantite);
            printf("-------------------\n");
            sleep(1);
        }
    } else {
        printf("Il n'y a pas de produits dans le panier.\n");
    }
}
Produit prendreProduitParCode(int code)
{
    // todo
}
int* aDansPanier(int code)
{
    // todo
}
void fermerCommande()
{
    // todo
}
