#include <stdio.h>

int main()
{
    int age;

    printf("Veuillez entrer ton âge: ");
    scanf("%d", &age);

    // Conditionnals
    if (age < 18) {
        printf("Tu es mineur que 18 ans.\n");
    } else if (age > 18 && age < 60) {
        printf("Tu es adulte.\n");
    } else {
        printf("Tu es agé.\n");
    }

    // Sortie
    printf("Ton âge est: %d\n", age);

    return 0;
}