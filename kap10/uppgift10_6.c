#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RAD 1000

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
		return 0;
	if (!remove_nl(a))
		fskip_line(f);
	return 1;
}

int main(void)
{
	char personerNamn[RAD],rad[RAD];
	FILE *personerFil;
	int radNummer = 0,slumpPerson;
	srand((int)time(NULL));
	/* Medföljande fil med namn på personerna är namn.txt */
	printf("Filen med namnen på personerna: ");
	if (!fread_line(personerNamn,RAD,stdin))
	{
		fprintf(stderr,"fread_line misslyckades.\n");
		exit(1);
	}
	if ((personerFil = fopen(personerNamn,"r")) == NULL)
	{
		fprintf(stderr,"Kan inte öppna filen %s.\n",personerNamn);
		exit(1);
	}
	while (fread_line(rad,RAD,personerFil))
		radNummer++;
	freopen(personerNamn,"r",personerFil);
	slumpPerson = rand()%radNummer;
	for (int i = 0; i <= slumpPerson; i++)
	{
		fread_line(rad,RAD,personerFil);
		if (i == slumpPerson)
			printf("%s\n",rad);
	}
	fclose(personerFil);
	exit(0);
}
