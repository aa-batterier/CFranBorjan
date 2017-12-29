#include <stdio.h>
#include <math.h>

int main(void)
{
	double i,j=0;
	printf("Skriv in ett godtyckligt antal tal, avsluta med EOF.\n");
	while (scanf("%lf",&i) == 1)
		j = fmax(i,j);
	printf("Största talet är %g.\n",j);
	return 0;
}
