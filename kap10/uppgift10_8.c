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
	char filNamn[RAD],rad[RAD];
	FILE *fil;
	printf("Namnet på filen: ");
	if (!fread_line(filNamn,RAD,stdin))
	{
		fprintf(stderr,"fread_line misslyckades.\n");
		return 1;
	}
	if ((fil = fopen(filNamn,"r")) == NULL)
	{
		fprintf(stderr,"Kan inte öppna filen %s.\n",filNamn);
		return 1;
	}
	while (fread_line(rad,RAD,fil))
	{
		int flag = 0;
		for (int i = 0; rad[i] != '\0'; i++)
			if (isspace(rad[i]))
				flag++;
		if (flag < strlen(rad))
			printf("%s\n",rad);
	}
	fclose(fil);
	return 0;
}
