#include <stdio.h>
#include <string.h>

#define RAD 1000

int fread_line(char *a,int n,FILE *f);
int remove_nl(char *a);
void fskip_line(FILE *f);

int main(void)
{
	char origNamn[RAD],nyNamn[RAD],searchText[RAD],rad[RAD];
	FILE *origFil,*nyFil;
	printf("Namnet på filen du ska leta i: ");
	if (!fread_line(origNamn,RAD,stdin))
	{
		fprintf(stderr,"fread_line misslyckades.\n");
		return 1;
	}
	if ((origFil = fopen(origNamn,"r")) == NULL)
	{
		fprintf(stderr,"Kan inte öppna filen %s.\n",origNamn);
		return 1;
	}
	printf("Namnet på filen du ska skriva till: ");
	if (!fread_line(nyNamn,RAD,stdin))
	{
		fprintf(stderr,"fread_line misslyckades.\n");
		return 1;
	}
	nyFil = fopen(nyNamn,"w");
	printf("Skriv in texten du söker efter: ");
	if (!fread_line(searchText,RAD,stdin))
	{
		fprintf(stderr,"fread_line misslyckades.\n");
		return 1;
	}
	while (fread_line(rad,RAD,origFil))
		if (strstr(rad,searchText) != NULL)
			fprintf(nyFil,"%s\n",rad);
	fclose(origFil);
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
