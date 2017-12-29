#include <stdio.h>

int main(void)
{
	int c,i=0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			i++;
	printf("\nAntal rader: %d\n",i);
	return 0;
}
