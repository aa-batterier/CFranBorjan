#include <stdio.h>
#include <string.h>
#include <ctype.h>

void no_white(char *f)
{
	char t[strlen(f)+1];
	int i = 0;
	for (int j = 0; f[j] != '\0'; j++)
	{
		if (isspace(f[j]))
			continue;
		else
		{
			t[i] = f[j];
			i++;
		}
	}
	t[i] = '\0';
	for (int j = 0; j < sizeof(f)/sizeof(f[0]); j++)
		f[j] = '\0';
	i = 0;
	while (t[i] != '\0')
	{
		f[i] = t[i];
		i++;
	}
	f[i] = '\0';
}

void to_lower(char *f)
{
	char t[strlen(f)+1];
	int i = 0;
	while (f[i] != '\0')
	{
		t[i] = tolower(f[i]);
		i++;
	}
	t[i] = '\0';
	i = 0;
	while (t[i] != '\0')
	{
		f[i] = t[i];
		i++;
	}
	f[i] = '\0';
}

int antal(const char *f, char c)
{
	int i = 0;
	for (int j = 0; f[j] != '\0'; j++)
		if (f[j] == c)
			i++;
	return i;
}

_Bool ar_anagram(char *s1,char *s2)
{
	no_white(s1);
	no_white(s2);
	to_lower(s1);
	to_lower(s2);
	if (strlen(s1) != strlen(s2))
		return 0;
	for (int i = 0; s1[i] != '\0'; i++)
		if (antal(s1,s1[i]) != antal(s2,s2[i]))
			return 0;
	return 1;
}

int main(void)
{
	char s1[100],s2[100];
	printf("Skriv in första texten: ");
	fgets(s1,100,stdin);
	printf("Skriv in andra texten: ");
	fgets(s2,100,stdin);
	if (ar_anagram(s1,s2))
		printf("Texterna är anagram.\n");
	else
		printf("Texterna är inte anagram.\n");
	return 0;
}
