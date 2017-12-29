#include <stdio.h>

int main(void)
{
	double b;
	printf("Skriv in elevens betyg: ");
	scanf("%lf",&b);
	if (b >= 45)
		printf("Eleven fick betyget A.\n");
	else if (45 > b && b >= 40)
		printf("Eleven fick betyget B.\n");
	else if (40 > b && b >= 35)
		printf("Eleven fick betyget C.\n");
	else if (35 > b && b >= 30)
		printf("Eleven fick betyget D.\n");
	else if (30 > b && b >= 25)
		printf("Eleven fick betyget E.\n");
	else
		printf("Eleven fick betyget F.\n");
	return 0;
}
