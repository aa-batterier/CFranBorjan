#include <stdio.h>
#include "ovning12_1.h"

int main(void)
{
	struct bil bil1 = {"123ABC","Volvo",1995,2340,550},bil2 = {"456DEF","BMW",1993,2500,700};
	printf("Bil nummer 1:\nRegistrerings nummer: %s\nFabrikat: %s\nÅrsmodell: %d\nTjänstevikt: %d\nEffekt: %d\n\nBil nummer 2:\nRegistrerings nummer: %s\nFabrikat: %s\nÅrsmodell: %d\nTjänstevikt %d\nEffekt: %d\n",bil1.regNr,bil1.fabrikat,bil1.year,bil1.vikt,bil1.effekt,bil2.regNr,bil2.fabrikat,bil2.year,bil2.vikt,bil2.effekt);
	return 0;
}
