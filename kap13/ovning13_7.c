#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N 100
#define ABNAMN_LANGD 20

struct abonnemang
{
	char namn[ABNAMN_LANGD];
	double per_manad;
	int fria_min;
	double extra_min,fria_gb,extra_gb;
};

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
	struct abonnemang a[N];
	int n = 0;
	FILE *f = fopen("mobildata2.txt","r");
	while (fread_line(a[n].namn,ABNAMN_LANGD,f))
	{
		fscanf(f,"%lf%d%lf%lf%lf",&a[n].per_manad,&a[n].fria_min,&a[n].extra_min,&a[n].fria_gb,&a[n].extra_gb);
		fskip_line(f);
		n++;
	}
	fclose(f);
	for (;;)
	{
		printf("Abonnemanget du söker: ");
		char sok[N];
		if (!fread_line(sok,N,stdin))
			break;
		int m = 0,i1 = 0,i2 = n;
		while (i1 <= i2)
		{
			m = (i1+i2)/2;
			if (strcoll(a[m].namn,sok) < 0)
				i1 = m+1;
			else if (strcoll(a[m].namn,sok) > 0)
				i2 = m-1;
			else
				break;
		}
		if (strcoll(a[m].namn,sok) == 0)
			printf("Abonnemanget: %s\nPris per månad: %g\nFria minuter: %d\nExtra minuter: %g\nFria GB: %g\nExtra GB: %g\n",a[m].namn,a[m].per_manad,a[m].fria_min,a[m].extra_min,a[m].fria_gb,a[m].extra_gb);
		else
			printf("Abonnemanget du söker finns inte.\n");
	}
	printf("\n");
	return 0;
}
