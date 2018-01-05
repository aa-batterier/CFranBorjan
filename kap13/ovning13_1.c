#include <stdio.h>
#include <string.h>

#define N 100

struct punk{double x,y;};

int fread_line(char *a,int n,FILE *f);
int remove_nl(char *a);
void fskip_line(FILE *f);

int main(void)
{
	struct punk punkter[N];
	FILE *fil = fopen("kurva.txt","r");
	if (fil == NULL)
	{
		fprintf(stderr,"Kan inte öppna filen.\n");
		return 1;
	}
	char rad[N];
	int i = 0,j = 0,k;
	for (; fread_line(rad,N,fil) && i < N; i++)
	{
		sscanf(rad+0,"%lf%n",&punkter[i].x,&k);
		sscanf(rad+k,"%lf%n",&punkter[i].y,&k);
	}
	fclose(fil);
	for (; j < i && (punkter[j].x > 0 || punkter[j].y > 0); j++);
	if (j < i)
		printf("Första punkten där både x och y kordinaten är negativa är (%g,%g).\n",punkter[j].x,punkter[j].y);
	else
		printf("Finns ingen punkt där både x och y är negativa.\n");
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
