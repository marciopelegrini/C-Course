#include <stdio.h>

void increase(int* value)
{
    printf("Avant increment. \n");
    printf("Le compteur vaut %d\n", (*value));
    printf("L'adresse de mémoire est : %d\n", value);
    
    printf("Après increment.\n");
    printf("Le compteur vaut %d\n", ++(*value));
    printf("L'adresse de mémoire est : %d\n", value);
}

int main()
{
    int cont = 10;

    printf("Avant increment. \n");
    printf("Le compteur vaut %d\n", cont);
    printf("L'adresse de mémoire est : %d\n", &cont);

    increase(&cont);

    printf("Après increment.\n");
    printf("Le compteur vaut %d\n", cont);
    printf("L'adresse de mémoire est : %d\n", &cont);

    return 0;
}