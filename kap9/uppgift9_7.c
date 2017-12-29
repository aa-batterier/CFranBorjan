#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 5

int tid(const char *t1,const char *t2)
{
	int mt1=0,mt2=0;
	for (int i = 0,j = 10; i < 2; i++,j /= 10)
	{
		mt1 += (t1[i] - '0') * j;
		mt2 += (t2[i] - '0') * j;
	}
	mt1 *= 60;
	mt2 *= 60;
	for (int i = 3,j = 10; i < 5; i++,j /= 10)
	{
		mt1 += (t1[i] - '0') * j;
		mt2 += (t1[i] - '0') * j;
	}
	if (mt2 < mt1)
	{
		mt1 = 24*60 - mt1;
		return mt1 + mt2;
	}
	else
		return mt1 - mt2;
}

_Bool remove_nl(char a[])
{
	int i = strlen(a)-1;
	if (a[i] == '\n')
	{
		a[i] = '\0';
		return 1;
	}
	return 0;
}

void skip_line(void)
{
	int i;
	while ((i = getchar()) != '\n' && i != EOF);
}

_Bool read_line(char a[], int n)
{
	if (fgets(a,n,stdin) == NULL)
		return 0;
	if (!remove_nl(a))
		skip_line();
	return 1;
}


int main(void)
{
	char t1[6],t2[6];
	printf("Första tiden: ");
	read_line(t1,6);
	printf("Andra tiden: ");
	read_line(t2,6);
	printf("Minuter mellan tiderna är %d.\n",tid(t1,t2));
	return 0;
}
