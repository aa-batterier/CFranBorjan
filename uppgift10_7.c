#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
	char filNamn[RAD],rad[RAD],nyRad[RAD],kons[] = "bcdfghjklmnpqrstvwxz";
	FILE *fil;
	/* Medföljande fil med rövarspråk är rovarsprak.txt */
	printf("Fil med rövarspråk: ");
	if (!fread_line(filNamn,RAD,stdin))
	{
		fprintf(stderr,"fread_line misslykades.\n");
		return 1;
	}
	if ((fil = fopen(filNamn,"r")) == NULL)
	{
		fprintf(stderr,"Kan inte öppna filen %s.\n",filNamn);
		return 1;
	}
	while (fread_line(rad,RAD,fil))
	{
		int j = 0;
		for (int i = 0; rad[i] != '\0'; i++,j++)
		{
			if (strchr(kons,tolower(rad[i])) != NULL)
			{
				nyRad[j] = rad[i];
				i += 2;
			}
			else
				nyRad[j] = rad[i];
		}
		nyRad[j] = '\0';
		printf("%s\n",nyRad);
	}
	fclose(fil);
	return 0;
}
