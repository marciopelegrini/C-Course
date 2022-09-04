#include <stdio.h>

int main()
{
    int values[5];

    for (int i = 0; i < 5; i++) {
        printf("Taper le %d/5 valeur : ", (i + 1));
        scanf("%d", &values[i]);
    }

    printf("Les valeurs informés sont: \n");

    for (int i = 0; i < 5; i++) {
        printf("%d\n", values[i]);
    }

    printf("%p\n", &values[1]);
    printf("%p\n", values);

    return 0;
}
