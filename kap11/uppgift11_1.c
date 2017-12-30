#include <stdio.h>

void revers(char *s)
{
	char *pLast = s;
	while (*pLast++);
	pLast -= 2;
	for (; s < pLast; s++,pLast--)
	{
		char temp = *pLast;
		*pLast = *s;
		*s = temp;
	}
}

int main(void)
{
	char string[] = "Hej! Hur har du det!";
	printf("%s\n",string);
	revers(string);
	printf("%s\n",string);
	return 0;
}
