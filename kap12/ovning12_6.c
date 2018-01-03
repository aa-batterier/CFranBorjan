#include <stdio.h>
#include "ovning12_1.h"

int main(void)
{
	struct person owner1 = {"Jan","Petterson",1964,0},owner2 = {"Johanna","Olofsson",1992,1};
	struct bil bil1 = {"123ABC","Volvo",1995,2340,550,&owner1},bil2 = {"456DEF","BMW",1993,2500,700,&owner2};
	printf("Bil nummer 1:\nRegistrerings nummer: %s\nFabrikat: %s\nÅrsmodell: %d\nTjänstevikt: %d\nEffekt: %d\nÄgare:\nFörnamn: %s\nEfternamn: %s\nFödd år: %d\n\nBil nummer 2:\nRegistrerings nummer: %s\nFabrikat: %s\nÅrsmodell: %d\nTjänstevikt %d\nEffekt: %d\nÄgare:\nFörnamn: %s\nEfternamn: %s\nFödd år: %d\n",bil1.regNr,bil1.fabrikat,bil1.year,bil1.vikt,bil1.effekt,bil1.owner->fornamn,bil1.owner->efternamn,bil1.owner->fodd_ar,bil2.regNr,bil2.fabrikat,bil2.year,bil2.vikt,bil2.effekt,bil2.owner->fornamn,bil2.owner->efternamn,bil2.owner->fodd_ar);
	return 0;
}
