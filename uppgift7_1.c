#include <stdio.h>

static int timme = 0,minut = 0;
static double temperatur = 0;

_Bool observation(int tim,int min,int temp)
{
	if (tim < 0 || tim > 23 || min < 0 || min > 59)
	{
		printf("Felaktig tidpunkt.\n");
		return 0;
	}
	if (temp < -100 || temp > 100)
	{
		printf("Felaktig temperatur.\n");
		return 0;
	}
	timme = tim;
	minut = min;
	temperatur = temp;
	return 1;
}

double aktuell_temp(void)
{
	return temperatur;
}

int obs_tim(void)
{
	return timme;
}

int obs_min(void)
{
	return minut;
}

int main(void)
{
	int i,t,m;
	double tmp;
	while(1)
	{
		printf("Vill du raportera aktuell temperatur, skriv 1, annar 0: ");
		if (scanf("%d",&i) != 1)
			break;
		if (i)
		{
			printf("Tidpunkt (tt mm): ");
			scanf("%d%d",&t,&m);
			printf("Temperatur: ");
			scanf("%lf",&tmp);
			if (!observation(t,m,tmp))
				printf("Rapporten misslyckades.\n");
		}
		else
			printf("Klockan %02d:%02d var det %.1f grader.\n",obs_tim(),obs_min(),aktuell_temp());
	}
	return 0;
}
