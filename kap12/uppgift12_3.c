#include <stdio.h>

typedef struct
{
	int taljare,namnare;
}rat_tal;

int main(void)
{
	rat_tal tal[3] = {{5,9},{1,3},{7,12}};
	for (int i = 0; i < 3; i++)
		printf("tal %d: %d/%d\n",i,tal[i].taljare,tal[i].namnare);
	return 0;
}
