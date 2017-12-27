#include <stdio.h>

#define MAX_LINE 1000

void fskip_line(FILE *f)
{
	int c;
	while ((c = fgetc(f)) != '\n' && c != EOF);
}

int remove_nl(char *a)
{
	int i = strlen(a)-1;
	if (a[i] == '\n')
	{
		a[i] = '\0';
		return 1;
	}
	return 0;
}

int fread_line(char *a,int n,FILE *f)
{
	if (fgets(a,n,f) == NULL)
	{
		fprintf(stderr,"Läsingen avbröts.\n");
		return 0;
	}
	if (!remove_nl(a))
	{
		fskip_line(f);
	}
	return 1;
}

int main(void)
{
	char fileName[MAX_LINE];
