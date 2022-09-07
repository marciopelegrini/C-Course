#include <stdio.h>
#include <math.h>

int main()
{
	int angle = 45;

	float res = cosh(angle);

	printf("Le cosinus hiperbolique de %d est %f", angle, res);

	return 0;
}
