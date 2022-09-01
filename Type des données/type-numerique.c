#include <stdio.h>
// Type des données

// Types numériques

int main()
{
    int numero_integer; // 7, 8, -2, 90 %d
    float numero_reel; // 2.4 3.1516    %f
    double numero_reel_aussi; //  %lf - plus grand que le float

    float num1, num2, moyenne;

    printf("Entrer le num 1: ");
    scanf("%f", &num1);

    printf("Entrer le num 2: ");
    scanf("%f", &num2);

    moyenne = (num1 + num2) / 2;
    printf("La moyenne des num est: %.1f\n", moyenne);

    return 0;
}