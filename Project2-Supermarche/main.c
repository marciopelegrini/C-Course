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

    printf("Entrez le prix du produit : \n");
    scanf("%f", &produits[compteur_produit].prix);

    printf("Le produit %s a bien été enregistrer.\n", strtok(produits[compteur_produit].nom, "\n"));
    produits[compteur_produit].code = (compteur_produit + 1);
    compteur_produit++;
    sleep(2);
    menu();
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
        sleep(2);
        menu();
    } else {
        printf("Il n'y a pas de produits enregistrés.\n");
        sleep(2);
        menu();
    }
}
void acheterProduit()
{
    int code;
    int se_trouve_au_marche = 0;
    if (compteur_produit > 0) {
        printf("Veuillez entrer le code du produit souhaité : \n");
        printf("================Produits disponibles==========\n");
        for (int i = 0; i < compteur_produit; i++) {
            infoProduit(produits[i]);
            printf("--------------------------\n");
            sleep(1);
        }
        scanf("%d", &code);
        getchar();

        for (int i = 0; i < compteur_produit; i++) {
            if (produits[i].code == code) {
                se_trouve_au_marche = 1;

                if (compteur_panier > 0) {
                    int* retour = aDansPanier(code);
                    if (retour[0] == 1) {
                        panier[retour[1]].quantite++;
                        printf("La quantité du produit %s a été augmenté dans lepanier.\n",
                            strtok(panier[retour[1]].produit.nom, "\n"));
                        sleep(2);
                        menu();
                    } else {
                        Produit p = prendreProduitParCode(code);
                        panier[compteur_panier].produit = p;
                        panier[compteur_panier].quantite = 1;
                        compteur_panier++;
                        printf("Le produit %s a bien été ajouté au panier.\n", strtok(p.nom, "\n"));
                        sleep(2);
                        menu();
                    }
                } else {
                    Produit p = prendreProduitParCode(code);
                    panier[compteur_panier].produit = p;
                    panier[compteur_panier].quantite = 1;
                    compteur_panier++;
                    printf("Le produit %s a bien été ajouté au panier.\n", strtok(p.nom, "\n"));
                    sleep(2);
                    menu();
                }
            }
        }
        if (se_trouve_au_marche < 1) {
            printf("Nous n'avons pas trouvé le produit avec le code %d.\n", code);
            sleep(2);
            menu();
        }
    } else {
        printf("Il n'y a pas de produits à acheter.\n");
        sleep(2);
        menu();
    }
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
        sleep(2);
        menu();
    } else {
        printf("Il n'y a pas de produits dans le panier.\n");
        sleep(2);
        menu();
    }
}
Produit prendreProduitParCode(int code)
{
    Produit p;
    for (int i = 0; i < compteur_produit; i++) {
        if (produits[i].code == code) {
            p = produits[i];
        }
    }
    return p;
}

int* aDansPanier(int code)
{
    int static retour[] = { 0, 0 };
    for (int i = 0; i < compteur_panier; i++) {
        if (panier[i].produit.code == code) {
            retour[0] = 1; // Le produit se trouve dans le panier
            retour[1] = i; // L'indice du produit dans le panier
        }
    }
    return retour;
}

void fermerCommande()
{
    if (compteur_panier > 0) {
        float valeurTotal = 0.0;
        printf("Produits dans le panier\n");
        printf("-----------------------\n");
        for (int i = 0; i < compteur_panier; i++) {
            Produit p = panier[i].produit;
            int quantite = panier[i].quantite;
            valeurTotal += p.prix * quantite;
            infoProduit(p);
            printf("Quantite : %d\n", quantite);
            printf("-------------\n");
            sleep(1);
        }
        printf("Votre facture est : %.2f\n", valeurTotal);

        // Netoyer le panier
        compteur_panier = 0;
        printf("Merci pour la visite.\n");
        sleep(5);
        menu();
    } else {
        printf("Vous n'avez pas de produits dans le panier encore.\n");
        sleep(3);
        menu();
    }
}
