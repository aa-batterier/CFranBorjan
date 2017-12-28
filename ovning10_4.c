#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

FILE *open_file(char *text,char *kommando)
{
	printf("%s",text);
	char namn[MAX_LINE];
	fread_line(namn,MAX_LINE,stdin);
	FILE *fil = fopen(namn,kommando);
	return fil;
}

int main(void)
{
	FILE *infil = open_file("Logfilen: ","r");
	char rad[MAX_LINE],namn[MAX_LINE] = "";
	int sum = 0;
	while (fread_line(rad,MAX_LINE,infil))
	{
		char delNamn[MAX_LINE],delNamn2[MAX_LINE] = "";
		int i = 0,k,min,delSum = 0;
		while (sscanf(rad+i,"%s%n",delNamn,&k) == 1 && !isdigit(delNamn[0]))
		{
			strcat(delNamn2,delNamn);
			i += k;
		}
		while (sscanf(rad+i,"%d%n",&min,&k) == 1)
		{
			delSum += min;
			i += k;
		}
		if (delSum > sum)
		{
			sum = delSum;
			strcpy(namn,delNamn2);
		}
	}
	fclose(infil);
	printf("Personen som har varit inloggad mest på datorerna är %s, sammanlagt har %s varit inloggad i %d minuter.\n",namn,namn,sum);
	return 0;
}
