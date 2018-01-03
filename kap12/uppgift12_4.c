#include <stdio.h>

typedef struct
{
	int taljare,namnare;
}rat_tal;

void forenkla(rat_tal *p)
{
	/*GCD*/
	int m = p->taljare,n = p->namnare;
	for (;;)
	{
		int r = m%n;
		if (r == 0)
			break;
		else
		{
			m = n;
			n = r;
		}
	}
	/*Förenkling*/
	p->taljare /= n;
	p->namnare /= n;
}

int main(void)
{
	rat_tal tal[4] = {{5,9},{1,3},{7,12},{6,9}};
	for (int i = 0; i < 4; i++)
	{
		forenkla(&tal[i]);
		printf("tal %d: %d/%d\n",i,tal[i].taljare,tal[i].namnare);
	}
	return 0;
}
