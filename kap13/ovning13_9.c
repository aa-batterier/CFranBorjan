#include <stdio.h>
#include <stdlib.h>
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

int jfr_abonnemang(const void *p1,const void *p2)
{
	const struct abonnemang *q1=p1,*q2=p2;
	return strcoll(q1->namn,q2->namn);
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
		struct abonnemang sok;
		if (!fread_line(sok.namn,N,stdin))
			break;
		struct abonnemang *hittat = bsearch(&sok,a,n,sizeof(struct abonnemang),jfr_abonnemang);
		if (hittat != NULL)
			printf("Abonnemanget: %s\nPris per månad: %g\nFria minuter: %d\nExtra minuter: %g\nFria GB: %g\nExtra GB: %g\n",hittat->namn,hittat->per_manad,hittat->fria_min,hittat->extra_min,hittat->fria_gb,hittat->extra_gb);
		else
			printf("Abonnemanget du söker finns inte.\n");
	}
	printf("\n");
	return 0;
}
