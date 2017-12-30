#include <stdio.h>

int main(int argc,char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr,"användning: %s <filnamn>\n",argv[0]);
		return 1;
	}
	char s[1000];
	while(1)
	{
		printf("Skriv in namn: ");
		scanf("%s",s);
		getchar();
		FILE *f = fopen(argv[1],"a");
		fputs(s,f);
		fclose(f);
		printf("Fortsätt: ");
	}
	return 0;
}
