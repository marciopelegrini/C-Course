#include <stdio.h>
#include <string.h>

union un_person {
    char nom[90];
    int age;
};

int main()
{
    union un_person person;

    strcpy(person.nom, "Bill Gates");
    printf("Données de %s\n", person.nom);

    person.age = 39;
    printf("Lui a %d années\n", person.age);

    printf("La variable 'person' prendre %ld bytes de mémoire\n", sizeof(person));

    return 0;
}