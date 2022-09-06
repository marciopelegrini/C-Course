#include <stdio.h>

//Étude à propos des fonctions

void message()
{
    printf("Bienvenue  \n");
}

int somme(int num1, int num2)
{
    int res = num1 + num2;
    return res;
}

void prochaine_char(char carac)
{
    printf("%c\n", carac + 1);
}

int main()
{
    printf("Salut...\n");

    message();

    printf("%d\n", somme(3, 4));

    prochaine_char('b');
    prochaine_char(97);

    return 0;
}
