#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Tar bort vita tecken i början och slutet av raden.*/
void trim(char *to,const char *from)
{
	/*char t[strlen(f)+1];*/
	int i = 0,j = strlen(from)-1;
	while (isspace(from[i]))
		i++;
	while (j >= 0 && isspace(from[j]))
		j--;
	if (j >= i)
		strncpy(to,from+i,j-i+1);
	to[j+1] = '\0';
	/*for (int k = 0; k < sizeof(f)/sizeof(f[0]); k++)
		f[k] = '\0';
	for (int k = 0; t[k] != '\0'; k++)
		f[k] = t[k];*/
}

int lang(char *f)
{
	/*int i = 0;
	while (f[i] != '\0')
		i++;
	return i;*/
	return strlen(f);
}

void first(char *to,const char *from)
{
	int i = 0;
	for (;!isspace(from[i]) && from[i] != '\0'; i++)
		to[i] = from[i];
	to[i] = '\0';
}

void last(char *to,const char *from)
{
	int j = 0;
	char temp[100];
	for (int i = strlen(from)-1; i >= 0 && !isspace(from[i]); i--)
	{
		temp[j] = from[i];
		j++;
	}
	temp[j] = '\0';
	j = 0;
	for (int i = strlen(temp)-1; i >= 0; i--)
	{
		to[j] = temp[i];
		j++;
	}
	to[j] = '\0';
}

_Bool remove_nl(char a[])
{
	int i = strlen(a)-1;
	if (a[i] == '\n')
	{
		a[i] = '\0';
		return 1;
	}
	return 0;
}

void skip_line(void)
{
	int i;
	while ((i = getchar()) != '\n' && i != EOF);
}

_Bool read_line(char a[], int n)
{
	if (fgets(a,n,stdin) == NULL)
		return 0;
	if (!remove_nl(a))
		skip_line();
	return 1;
}

int main(void)
{
	char str[100],trm[100],frs[100],lst[100];
	printf("Skriv in en text:\n");
	read_line(str,100);
	trim(trm,str);
	int lng = lang(trm);
	first(frs,trm);
	last(lst,trm);
	printf("Längden på texten är %d.\nFörsta ordet är %s.\nSista ordet är %s.\n",lng,frs,lst);
	return 0;
}
