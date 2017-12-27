#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	double x1,y1,x2,y2;
	printf("Skriv in x och y värdena för första punkten: ");
	scanf("%lf%lf",&x1,&y1);
	getchar();
	printf("Skriv in x och y värdena för andra punkten: ");
	scanf("%lf%lf",&x2,&y2);
	getchar();
	printf("Avståndet mellan punkterna är %g.\n",sqrt(pow((x1-x2),2)+pow((y1-y2),2)));
	return 0;
}
