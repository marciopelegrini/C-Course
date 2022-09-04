#include <stdio.h>

int main()
{
    int values[5] = { 1, 2, 3, 4, 5 };

    for (int i = 0; i < 5; i++) {
        printf("Le valeur %d a %ld bytes\n", values[i], sizeof(values[i]));
    }

    printf("Le tableau values a %ld bytes\n", sizeof(values));

    printf("values[0] vaut %d et l'adresse de mémoire est: %p\n", values[0], values[0]);

    printf("*(values) vaut %d et l'adresse de mémoire est: %p\n", *(values), *(values));

    return 0;
}
