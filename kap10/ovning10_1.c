#include <stdio.h>

int main(void)
{
	char s[100];
	while(1)
	{
		printf("Skriv in namn: ");
		scanf("%s",s);
		getchar();
		FILE *f = fopen("personer.txt","a");
		fputs(s,f);
		fclose(f);
		printf("Fortsätt: ");
	}
	return 0;
}
