#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

int fread_line(char *a,int n,FILE *f);
int remove_nl(char *a);
void fskip_line(FILE *f);

int main(void)
{
	double sum = 0.0,hogst = -273.0,antal = 0.0,temp;
	char filNamn[MAX_LINE];
	/* Medföjlande fil är temperatur.txt */
	printf("Namn på filen med temperaturerna: ");
	if (!fread_line(filNamn,MAX_LINE,stdin))
	{
		fprintf(stderr,"fread_line misslyckades\n");
		return 1;
	}
	FILE *infil = fopen(filNamn,"r");
	while (fscanf(infil,"%lf",&temp) == 1)
	{
		if (temp > hogst)
			hogst = temp;
		sum += temp;
		antal++;
	}
	fclose(infil);
	printf("Högsta temperaturen var %g.\nMedelvärdet var %g.\n",hogst,sum/antal);
	return 0;
}

int fread_line(char *a,int n,FILE *f)
{
	if (fgets(a,n,f) == NULL)
		return 0;
	if (!remove_nl(a))
		fskip_line(f);
	return 1;
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

void fskip_line(FILE *f)
{
	int c;
	while ((c = fgetc(f)) != '\n' && c != EOF);
}
