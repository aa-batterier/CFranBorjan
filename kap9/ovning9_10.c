#include <stdio.h>
#include <ctype.h>

void remove_white(char *to,const char *from)
{
	int i = 0;
	for (int j = 0; from[j] != '\0'; j++)
	{
		if (isspace(from[j]))
			continue;
		else
		{
			to[i] = from[j];
			i++;
		}
	}
	to[i] = '\0';
}

int main(void)
{
	char to[24],from[] = "Hej hur har du det idag\0";
	remove_white(to,from);
	printf("Text med vita tecken: %s\nText utan vita tecken: %s\n",from,to);
	return 0;
}
