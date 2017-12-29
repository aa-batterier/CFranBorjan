#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

int fread_line(char *array,int number,FILE *file);
int remove_nl(char *array);
void fskip_line(FILE *file);
void print_line(char *line);

int main(void)
{
	char filNamn[MAX_LINE],rad[MAX_LINE];
	printf("Namnet på filen: ");
	if (!fread_line(filNamn,MAX_LINE,stdin))
	{
		fprintf(stderr,"fread_line misslyckades\n");
		return 1;
	}
	FILE *fil = fopen(filNamn,"r");
	while (fread_line(rad,MAX_LINE,fil))
		print_line(rad);
	return 0;
}

int fread_line(char *array,int number,FILE *file)
{
	if (fgets(array,number,file) == NULL)
		return 0;
	if (!remove_nl(array))
		fskip_line(file);
	return 1;
}

int remove_nl(char *array)
{
	int last = strlen(array)-1;
	if (array[last] == '\n')
	{
		array[last] = '\0';
		return 1;
	}
	return 0;
}

void fskip_line(FILE *file)
{
	int c;
	while ((c = fgetc(file)) != '\n' && c != EOF);
}

void print_line(char *line)
{
	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '\t')
			printf("   ");
		else
			printf("%c",line[i]);
	}
	printf("\n");
}
