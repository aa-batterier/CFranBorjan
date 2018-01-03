#include <stdio.h>
#include "ovning12_1.h"

int main(void)
{
	struct bil bil1 = {"123ABC","Volvo",1995,2340,550},bil2 = {"456DEF","BMW",1993,2500,700},bilArray[3] = {{"789GHI","Audi",2004,2500,700},{"132JKL","Porsche",1982,2000,500},{"321MNO","Saab",1999,2475,625}};
	printf("Bil nummer 1:\nRegistrerings nummer: %s\nFabrikat: %s\nÅrsmodell: %d\nTjänstevikt: %d\nEffekt: %d\n\nBil nummer 2:\nRegistrerings nummer: %s\nFabrikat: %s\nÅrsmodell: %d\nTjänstevikt %d\nEffekt: %d\n\n",bil1.regNr,bil1.fabrikat,bil1.year,bil1.vikt,bil1.effekt,bil2.regNr,bil2.fabrikat,bil2.year,bil2.vikt,bil2.effekt);
	for (int i = 0; i < 3; i++)
		printf("Bil %d:\nRegistrerings nummer: %s\nFabrikat: %s\nÅrsmodell: %d\nTjänstevikt: %d\nEffekt: %d\n\n",i,bilArray[i].regNr,bilArray[i].fabrikat,bilArray[i].year,bilArray[i].vikt,bilArray[i].effekt); 
	return 0;
}
