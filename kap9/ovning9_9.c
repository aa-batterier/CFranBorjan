#include <stdio.h>

void replace(char *to,const char *from,char old,char new)
{
	int i = 0;
	for (; from[i] != '\0'; i++)
	{
		if (from[i] == old)
			to[i] = new;
		else
			to[i] = from[i];
	}
	to[i] = '\0';
}

int main(void)
{
	char to[24],from[] = "Hej hur har du det idag\0",old = 'r',new = 'T';
	replace(to,from,old,new);
	printf("Orginal texten: %s\nKopierade och ändrade texten: %s\n",from,to);
	return 0;
}
