#include <stdio.h>

int main(void)
{
	double b,a,g;
	printf("Skriv in pris för biljett: ");
	scanf("%lf",&b);
	getchar();
	printf("Skriv in pris för årskort: ");
	scanf("%lf",&a);
	getchar();
	printf("Skriv in antal gånger som du ska besöka gymmet: ");
	scanf("%lf",&g);
	getchar();
	if (g*b >= g+a)
		printf("Det lönar sig att köpa årskort.\n");
	else
		printf("Det lönar sig att köpa biljetter.\n");
	return 0;
}
