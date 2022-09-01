
#include <stdio.h>

// Vectors unidimensionnel
//  char[50];
int main()
{
    // Strings
    char nom[50];
    printf("Qulle est votre nom: ");
    gets(nom);
    printf("Ton nom est: %s\n", nom);

    // Charactères
    char letters[26];
    int count = 0;
    for (int i = 97; i <= 122; i++) {
        letters[count] = i;
        count++;
    }

    // Impression du vector
    for (int i = 0; i < 26; i++) {
        printf("%d == %c\n", letters[i], letters[i]);
    }

    // Integers
    int numbers[20];

    // Real or Float
    float numbers2[10];

    
    return 0;
}