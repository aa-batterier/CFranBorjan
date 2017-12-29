#include <stdio.h>

int main(void)
{
	double i,j=1;
	for (i = j; i < 0.00001; i -= 1/i+1)
		for (j = i; j == i; j += 1/j+1);
	printf("Summan blir %g.\n",j);
	return 0;
}
