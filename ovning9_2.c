#include <stdio.h>

int main(void)
{
	int c,i=0;
	while ((c = getchar()) != EOF)
		i++;
	printf("\nAntal tecken: %d\n",i);
	return 0;
}
