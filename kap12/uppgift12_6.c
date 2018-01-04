#include <stdio.h>
#include <string.h>

#define ABNAMN_LANGD 20

struct abonnemang
{
	char namn[ABNAMN_LANGD];
	double per_manand;
	int fria_min;
	double extra_min,fria_gb,extra_gb;
};

void skip_line(void)
{
	int c;
	while ((c = getchar) != '\n' || c != EOF);
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

int main(void)
{
	struct abonnemang b1,b2;
	const int size = sizeof(struct abonnemang);
	FILE *f = fopen("mobildata.dat","r+b");
	if (f == NULL)
		f = fopen("mobildata.dat","w+b");
	while (1)
	{
		printf("Namn: ");
		if (!read_line(b1.namn,ABNAMN_LANGD))
			break;
		printf("Ange data för %s\n",b1.namn);
		scanf("%lf%d%lf%lf%lf",&b1.per_manad,&b1.fria_min,&b1.extra_min,&b1.fria_gb,&b1.extra_gb);
		skip_line();
		rewind(f);
		int finns = 0;
		while (fread(&b2,size,1,f) == 1)
		{
			if (strcmp(b1.namn,b2.namn) == 0)
			{
				finns = 1;
				fseek(f,-size,SEEK_CUR);
				fwrite(&b1,size,1,f);
				break;
			}
		}
		if (!finns)
			fwrite(&b1,size,1,f);
	}
	fclose(f);
}
