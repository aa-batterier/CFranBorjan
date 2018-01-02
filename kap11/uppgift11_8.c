#include <stdio.h>
#include <string.h>
#include <ctype.h>

void split(char *s,char *tab[],int max)
{
	for (int i = 0; i < max; i++)
		tab[i] = NULL;
	for (int i = 0; i < max; i++)
	{
		while (*s && *s == ' ')
			s++;
		if (!*s)
			return;
		tab[i] = s;
		while (*s && *s != ' ')
			s++;
		if (!*s)
			return;
		*s++ = '\0';
	}
}

int main(void)
{
	char text[] = "Jag heter Andreas Johansson",*del[7];
	split(text,del,7);
	for (int i = 0; del[i]; i++)
		printf("%s\n",del[i]);
	return 0;
}
