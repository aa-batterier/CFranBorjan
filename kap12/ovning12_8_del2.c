#include <stdio.h>
#include "ovning12_1.h"

int main(void)
{
	FILE *binFil = fopen(FILNAMN,"rb");
	if (binFil == NULL)
	{
		fprintf(stderr,"Filen %s kunde inte öppnas.\n",FILNAMN);
		return 1;
	}
	fseek(binFil,0,SEEK_END);
	int antal = ftell(binFil)/sizeof(struct bil);
	struct bil bilar[antal];
	rewind(binFil);
	fread(&bilar,sizeof(struct bil),antal,binFil);
	fclose(binFil);
	for (int i = 0; i < antal; i++)
		printf("Bil %d:\nRegistrerings nummer: %s\nFabrikat: %s\nÅrsmodell: %d\nTjänstevikt: %d\nEffekt: %d\n\n",i,bilar[i].regNr,bilar[i].fabrikat,bilar[i].year,bilar[i].vikt,bilar[i].effekt);
	return 0;
}
