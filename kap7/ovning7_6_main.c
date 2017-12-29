#include <stdio.h>
#include "ovning7_6.h"

int main(void)
{
	int kund,nr;
	while(1)
	{
		printf("Skriv 1 om du är kund, 0 annars: ");
		if (scanf("%d",&kund) != 1)
			break;
		if (kund)
		{
			printf("Du fick nr: %d\n",ta_lapp());
			printf("Kund %d betjanas just nu.\n",betjanas());
		}
		else
		{
			nr = betjana_kund();
			if (nr > 0)
				printf("Betjäna nr: %d\n",nr);
			else
				printf("Inga kunder i kö\n");
		}
	}
	return 0;
}
