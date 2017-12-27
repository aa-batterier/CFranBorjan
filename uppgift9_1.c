#include <stdio.h>
#include <string.h>

void baklanges(char *to,const char *from)
{
	int i = 0;
	for (int j = strlen(from)-1; j >= 0; j--)
	{
		to[i] = from[j];
		i++;
	}
	to[i] = '\0';
}

int main(void)
{
	char to[24],from[] = "Hej hur har du det idag\0";
	baklanges(to,from);
	printf("Orginal texten: %s\nTexten baklänges: %s\n",from,to);
	return 0;
}
