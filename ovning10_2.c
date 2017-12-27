#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

void skip_line(void)
{
	int c;
	while((c = getchar()) != '\n' || c == EOF);
}

int remove_nl(char *a)
{
	int i = strlen(a)-1;
	if (a[i] == '\n')
	{
		a[i] = '\0';
		return 1;
	}
	return 0;
}

int read_line(char *to,FILE *from,int size)
{
	if (fgets(to,size,from) == NULL)
	{
		fprintf(stderr,"Läsningen avbröts.\n");
		return 0;
	}
	if (!remove_nl(to))
	{
		skip_line();
	}
	return 1;
}

int main(void)
{
	FILE *file;
	char fileName[MAX_LINE],fileLine[MAX_LINE];
	printf("Skriv in filens namn: ");
	read_line(fileName,stdin,MAX_LINE);
	file = fopen(fileName,"r");
	while(read_line(fileLine,file,MAX_LINE))
	{
		int i = 0;
		for (; (fileLine[i] != '/' && fileLine[i+1] != '/') && fileLine[i] != '\0'; i++);
		printf("%g\n",((double)(strlen(fileLine)-i)/(double)strlen(fileLine))*100);
	}
	fclose(file);
	return 0;
}
