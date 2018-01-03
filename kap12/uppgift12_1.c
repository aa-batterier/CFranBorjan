#include <stdio.h>

#define MAX 1000

typedef struct
{
	char titel[MAX],forfattare[MAX];
	int sidor,pris;
}bok;

int main(void)
{
	bok boknr[2] = {{"Advanced Programming in the UNIX Environment","W.Richard Stevens, Stephen A.Rago",994,892},{"The Joy of Clojure","Michael Fogus, Chris Houser",477,599}};
	for (int i = 0; i < 2; i++)
		printf("Bok %d:\nTitel: %s\nFörfattare: %s\nSidantal: %d\nPris: %d\n\n",i,boknr[i].titel,boknr[i].forfattare,boknr[i].sidor,boknr[i].pris);
	return 0;
}
