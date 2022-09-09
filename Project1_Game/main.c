#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dificulte;
    int val1;
    int val2;
    int operation;
    int resultat;
} Calculer;

void jouer();

void afficherInfo(Calculer calc);

int points = 0;

int main() {
    //Doit être jouer 1 fois seulement
    srand(time(NULL));
    jouer();
    return 0;
}

void jouer() {
    //todo
}

void afficherInfo(Calculer calc) {
    //todo
}

int somme(int reponse, Calculer calc) {
    //todo
}

int subtraction(int reponse, Calculer calc) {
    //todo
}

int multiplier(int reponse, Calculer calc) {
    //todo
}
