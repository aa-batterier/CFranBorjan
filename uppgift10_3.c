#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000
#define TEMP "temp.txt"

int fread_line(char *a,int n,FILE *f);
int remove_nl(char *a);
void fskip_line(FILE *f);
void fprint_line(char *line,FILE *file);

int main(void)
{
	FILE *fil,*temp;
	char filNamn[MAX_LINE],rad[MAX_LINE];
	printf("Namnet på filen: ");
	if (!fread_line(filNamn,MAX_LINE,stdin))
	{
		fprintf(stderr,"fread_line misslyckades\n");
		return 1;
	}
	if ((fil = fopen(filNamn,"r")) == NULL)
	{
		fprintf(stderr,"Kan inte öppna filen.\n");
		return 1;
	}
	temp = fopen(TEMP,"w");
	while (fread_line(rad,MAX_LINE,fil))
		fprint_line(rad,temp);
	freopen(filNamn,"w",fil);
	freopen(TEMP,"r",temp);
	while (fread_line(rad,MAX_LINE,temp))
		fprintf(fil,"%s\n",rad);
	fclose(fil);
	remove(TEMP);
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

void fprint_line(char *line,FILE *file)
{
	char new_line[MAX_LINE] = "";
	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '\t')
			strncat(new_line,"   ",3);
		else
			strncat(new_line,&line[i],1);
	}
	new_line[strlen(new_line)] = '\0';
	fprintf(file,"%s\n",new_line);
}
