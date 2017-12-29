#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr,"användande: %s <radie>\n",argv[0]);
		exit(1);
	}
	printf("Volymen av sfären med radien %s är %g.\nArean av sfären med radien %s är %g\n",argv[1],(4*M_PI*pow(atof(argv[1]),3))/3,argv[1],4*M_PI*pow(atof(argv[1]),2));
	exit(0);
}
