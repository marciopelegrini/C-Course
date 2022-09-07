#include <stdio.h>

enum jours_semaine {
    lundi,
    mardi,
    mercredi,
    jeudi,
    vendredi,
    samedi,
    dimanche
};

int main()
{
    enum jours_semaine d1, d2;

    d1 = mardi;
    d2 = 1;

    if (d1 == d2) {
        printf("Les jours sont égales\n");
    } else {
        printf("Les jours ne sont pas égales\n");
    }

    return 0;
}