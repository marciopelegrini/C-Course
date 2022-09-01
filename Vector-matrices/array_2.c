
#include <stdio.h>

// Vectors unidimensionnel
//  char[50];
int main()
{
    // Integers
    int numbers[5];
    numbers[0] = 1;
    numbers[1] = 3;
    numbers[2] = 5;
    numbers[3] = 7;
    numbers[4] = 9;

    // Real or Float
    float numbers2[5];
    for (int i = 0; i < 5; i++) {
        numbers2[i] = (float)numbers[i] / (float)2;
    }

    for (int i = 4; i >= 0; i--) {
        printf("%.2f\n", numbers2[i]);
    }

    return 0;
}