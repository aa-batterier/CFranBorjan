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
	FILE *f = fopen("mobildata.txt","r");
	while (fread_line(a[n].namn,ABNAMN_LANGD,f))
	{
		fscanf(f,"%lf%d%lf%lf%lf",&a[n].per_manad,&a[n].fria_min,&a[n].extra_min,&a[n].fria_gb,&a[n].extra_gb);
		fskip_line(f);
		n++;
	}
	setlocale(LC_ALL,"");
	for (int i = 0; i < n; i++)
	{
		int s = i;
		for (int j = i; j < n; j++)
			if (strcoll(a[j].namn,a[s].namn) < 0)
				s = j;
		struct abonnemang temp = a[i];
		a[i] = a[s];
		a[s] = temp;
	}
	setlocale(LC_ALL,"C");
	FILE *nyFil = fopen("mobildata2.txt","w");
	for (int i = 0; i < n; i++)
		fprintf(nyFil,"%s\n%g %d %g %g %g\n",a[i].namn,a[i].per_manad,a[i].fria_min,a[i].extra_min,a[i].fria_gb,a[i].extra_gb);
	fclose(nyFil);
	return 0;
}
