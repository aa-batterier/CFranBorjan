#include <stdio.h>
#include "ovning12_1.h"

#define ANTAL 2

int main(void)
{
	struct bil bilar[ANTAL] = {{"123ABC","Volvo",2012,2750,700},{"456DEF","Saab",2007,2500,650}};
	FILE *binFil = fopen(FILNAMN,"wb");
	fwrite(&bilar,sizeof(struct bil),ANTAL,binFil);
	fclose(binFil);
	return 0;
}
