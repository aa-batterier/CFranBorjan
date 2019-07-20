#include <stdio.h>

int main(void)
{
	int tid,tim,min,sek;
	printf("Tiden det tog programmet att köra i sekunder: ");
	scanf("%d",&tid);
	tim = tid/3600;
	min = tim/60;
	sek = tid;
	printf("Antal timmar blev %d.\nAntal minuter blev %d.\nAntal sekunder blev %d.\n",tim,min,sek);
	return 0;
}
