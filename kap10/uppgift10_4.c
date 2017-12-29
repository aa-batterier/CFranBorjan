#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000
#define BMI 30

int fread_line(char *a,int n,FILE *f);
int remove_nl(char *a);
void fskip_line(FILE *f);
void noll(char *a);

int main(void)
{
	FILE *personerFil,*nyFil;
	char rad[MAX_LINE],personerNamn[MAX_LINE],nyNamn[MAX_LINE];
	/* Medföljande fil med personer är personer.txt */
	printf("Namn på filen med personerna: ");
	if (!fread_line(personerNamn,MAX_LINE,stdin))
	{
		fprintf(stderr,"fread_line misslyckades\n");
		return 1;
	}
	printf("Namn på filen med de överviktiga personerna: ");
	if (!fread_line(nyNamn,MAX_LINE,stdin))
	{
		fprintf(stderr,"fread_line misslyckades\n");
		return 1;
	}
	if ((personerFil = fopen(personerNamn,"r")) == NULL)
	{
		fprintf(stderr,"Kan inte öppna filen\n");
		return 1;
	}
	nyFil = fopen(nyNamn,"w");
	char rad1[MAX_LINE] = "",rad2[MAX_LINE] = "",ord[MAX_LINE];
	while (fread_line(rad,MAX_LINE,personerFil))
	{
		double value[3];
		int i = 0,k;
		if (!isdigit(rad[0]))
		{
			noll(rad1);
			while (sscanf(rad+i,"%s%n",ord,&k) == 1)
			{
				strcat(rad1,ord);
				strcat(rad1," ");
				i = i + k;
			}
			continue;
		}
		i = 0;
		int j = 0;
		noll(rad2);
		while (sscanf(rad+i,"%lf%n",&value[j],&k) == 1)
		{
			sprintf(ord,"%g",value[j]);
			strcat(rad2,ord);
			strcat(rad2," ");
			i = i + k;
			j++;
		}
		double bmi = value[2]/((value[1]/100)*(value[1]/100));
		if (bmi > BMI)
			fprintf(nyFil,"%s\n%s\n",rad1,rad2);
	}
	fclose(personerFil);
	fclose(nyFil);
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

void noll(char *a)
{
	for (int i = 0; a[i] != '\0'; i++)
		a[i] = '\0';
}
