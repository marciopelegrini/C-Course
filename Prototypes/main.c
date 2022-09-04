#include <stdio.h> //Fichier header
#include "tools.h"

int main()
{
    int n1, n2, ret_s, ret_m;
    message();

    printf("Tapez le 1er numéro : ");
    scanf("%d", &n1);

    printf("Tapez le 2ème numéro : ");
    scanf("%d", &n2);

    ret_s = somme(n1, n2);
    printf("La somme est : %d\n", ret_s);

    ret_m = multiplication(n1, n2);
    printf("La multiplication est : %d\n", ret_m);

    return 0;
}