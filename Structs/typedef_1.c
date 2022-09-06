#include <stdio.h>

// Rédefinition des types

int main()
{
    typedef float note;

    note examen1 = 7.0;
    note examen2 = 6.5;

    note somme = examen1 + examen2;

    printf("La somme est : %.2f\n", somme);
    
    return 0;
}