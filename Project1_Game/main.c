#include <stdio.h>
#include <stdlib.h>
#include "time.h"

typedef struct {
    int dificulte;
    int val1;
    int val2;
    int operation;
    int resultat;
} Calculer;

void jouer();
void afficherInfo(Calculer calc);
int somme(int reponse, Calculer calc);
int soustraction(int reponse, Calculer calc);
int multiplication(int reponse, Calculer calc);
int points = 0;

int main() {
    //Doit être jouer 1 fois seulement
    srand(time(NULL));
    jouer();
    return 0;
}

void jouer() {
    Calculer calc;
    int dificulte;

    printf("Tapez le niveau de dificulté souhaité [1, 2, 3 ou 4] : ");
    scanf("%d", &dificulte);
    calc.dificulte = dificulte;

    //Gération d'un inte aleatoire entre 0 et 2
    //0 = somme, 1 = soustraction, 2 = multiplication
    calc.operation = rand() % 3;
    if (calc.dificulte == 1) {
        //Mode facile
        calc.val1 = rand() % 11; //0 à 10
        calc.val2 = rand() % 11;
    } else if (calc.dificulte == 2) {
        //Mode moyenne
        calc.val1 = rand() % 101; // 0 à 100
        calc.val2 = rand() % 101;
    } else if (calc.dificulte == 3) {
        // Mode Dificile
        calc.val1 = rand() % 1001; //0 à 1000
        calc.val2 = rand() % 1001;
    } else if (calc.dificulte == 4) {
        //Mode Insane
        calc.val1 = rand() % 10001; // 0 à 10.000
        calc.val2 = rand() % 10001;
    } else {
        //Mode Ultra
        calc.val1 = rand() % 100001; // 0 à 100.000
        calc.val2 = rand() % 100001;
    }
    int reponse;
    printf("\nTapez le résultat pour l'opération suivante => ");

    //Somme
    if (calc.operation == 0) {
        printf("%d + %d : ", calc.val1, calc.val2);
        scanf("%d", &reponse);
        if (somme(reponse, calc)) {
            points += 1;
            printf("Vous avez %d point(s)\n", points);
        }//Soustraction
        else if (calc.operation == 1) {
            printf("%d - %d : ", calc.val1, calc.val2);
            scanf("%d", &reponse);
            if (soustraction(reponse, calc)) {
                points += 1;
                printf("Vous avez %d point(s).\n", points);
            }
        }//Multiplication
        else if (calc.operation == 2) {
            printf("%d * %d : ", calc.val1, calc.val2);
            scanf("%d", &reponse);

            if (multiplication(reponse, calc)) {
                points += 1;
                printf("Vous avez %d point(s).\n", points);
            }
        }//Inconnu
        else {
            printf("L'operation %d n'est pas reconnue.\n", calc.operation);
        }
        afficherInfo( calc);

        // Recommencer le jeu?
        printf("Voulez-vous continuer à jouer ? [1 - Oui, 0 - Non]\n");
        int continuer;
        scanf("%d", &continuer);

        if (continuer) {
            jouer();
        } else {
            printf("Vous avez fini avec %d point(s).\n", points);
            printf("À la prochaine.");
            exit(0);
        }
    }
}

void afficherInfo(Calculer calc) {
    char op[25];
    if (calc.operation == 0) { // 0 c'est la somme
        sprintf(op, "Somme");
    } else if (calc.operation == 1) {
        sprintf(op, "Soustraction");
    } else if (calc.operation == 2) {
        sprintf(op, "Multiplication");
    } else {
        sprintf(op, "Opération inconnue");
    }
    printf("Valeur 1 : %d\nValeur 2 : %d\nDificulté : %d \nOpération : %s\n\n",
           calc.val1, calc.val2, calc.dificulte, op);
}

int somme(int reponse, Calculer calc) {
    int result = calc.val1 + calc.val2;
    calc.resultat = result;
    int correct = 0;
    if (reponse == calc.resultat) {
        printf("La réponse est correcte!\n");
        correct = 1;
    } else {
        printf("La réponse n'est pas correcte!\n");
    }
    printf("%d + %d = %d\n", calc.val1, calc.val2, calc.resultat);

    return correct;
}

int soustraction(int reponse, Calculer calc) {
    int result = calc.val1 - calc.val2;
    calc.resultat = result;
    int correct = 0;
    if (reponse == calc.resultat) {
        printf("La réponse est correcte!\n");
        correct = 1;
    } else {
        printf("La réponse n'est pas correcte!\n");
    }
    printf("%d - %d = %d\n", calc.val1, calc.val2, calc.resultat);

    return correct;
}

int multiplication(int reponse, Calculer calc) {
    int result = calc.val1 * calc.val2;
    calc.resultat = result;
    int correct = 0;
    if (reponse == calc.resultat) {
        printf("La réponse est correcte!\n");
        correct = 1;
    } else {
        printf("La réponse n'est pas correcte!\n");
    }
    printf("%d * %d = %d\n", calc.val1, calc.val2, calc.resultat);

    return correct;
}
