#include <stdio.h>
#include <string.h>
#include <locale.h>

#define PNAMN_LANGD 30

struct person
{
	char fornamn[PNAMN_LANGD],efternamn[PNAMN_LANGD];
	int fodd_ar;
};

void sortera(struct person a[], int start,int slut)
{
	setlocale(LC_ALL,"");
	for (int k = start; k < slut; k++)
	{
		int m = k;
		for (int i = k; i <= slut; i++)
			if (strcoll(a[i].efternamn,a[m].efternamn) < 0 || (strcoll(a[i].efternamn,a[m].efternamn) == 0 && strcoll(a[i].fornamn,a[m].fornamn) < 0))
				m = i;
		struct person temp = a[k];
		a[k] = a[m];
		a[m] = temp;
	}
	setlocale(LC_ALL,"C");
}

void skip_line(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
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

int read_line(char *a,int n)
{
	if (fgets(a,n,stdin) == NULL)
		return 0;
	if (!remove_nl(a))
		skip_line();
	return 1;
}

int bin_sok(const struct person a[],const int start,const int slut,const struct person *sok)
{
	int i1 = start,i2 = slut,m = 0;
	while (i1 <= i2)
	{
		m = (i1+i2)/2;
		if (strcoll(a[m].efternamn,sok->efternamn) < 0 || (strcoll(a[m].efternamn,sok->efternamn) == 0 && strcoll(a[m].fornamn,sok->fornamn) < 0))
			i1 = m+1;
		else if (strcoll(a[m].efternamn,sok->efternamn) > 0 || (strcoll(a[m].efternamn,sok->efternamn) == 0 && strcoll(a[m].fornamn,sok->fornamn) > 0))
			i2 = m-1;
		else
			break;
	}
	if (strcoll(a[m].efternamn,sok->efternamn) == 0 && strcoll(a[m].fornamn,sok->fornamn) == 0)
		return m;
	else
		return start-1;
}

int main(void)
{
	int start = 0,slut = 5-1;
	struct person pA[] = {{"Johan","Persson",1993},{"Hannes","Albertsson",1954},{"Julia","Svensson",1997},{"Gunnar","Bergquist",2007},{"Maria","Stensson",1999}},sok;
	sortera(pA,start,slut);
	for (;;)
	{
		printf("Personen du söker:\nFörnamn: ");
		if (!read_line(sok.fornamn,PNAMN_LANGD))
			break;
		printf("Efternamn: ");
		if (!read_line(sok.efternamn,PNAMN_LANGD))
			break;
		int hittat = bin_sok(pA,start,slut,&sok);
		if (hittat < start)
			printf("Personen du söker finns inte.\n");
		else
			printf("Personen du söker:\n%s\n%s\n%d\n",pA[hittat].fornamn,pA[hittat].efternamn,pA[hittat].fodd_ar);
	}
	printf("\n");
	return 0;
}
