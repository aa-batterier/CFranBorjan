#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

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

void tolower_str(char *to,const char *from)
{
	setlocale(LC_ALL,"");
	int i = 0;
	for (; from[i] != '\0'; i++)
		to[i] = tolower(from[i]);
	to[i] = '\0';
}

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

void palindrom(char *s)
{
	char noWhite[strlen(s)];
	remove_white(noWhite,s);
	char toLower[strlen(noWhite)];
	tolower_str(toLower,noWhite);
	char bakLanges[strlen(toLower)];
	baklanges(bakLanges,toLower);
	if (strncmp(bakLanges,toLower,strlen(toLower)) == 0)
		printf("%s är ett palindrom.\n",s);
	else
		printf("%s är inte ett palindrom.\n",s);
}

int main(void)
{
	char s[100];
	fgets(s,100,stdin);
	palindrom(s);
	return 0;
}
