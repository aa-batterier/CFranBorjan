#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL,"");
	char teck = getchar();
	if (isdigit(teck))
		printf("Det är en siffra.\n");
	if (islower(teck))
		printf("Det är en liten bokstav\nMotsvarande stor bokstav är: %c\n",toupper(teck));
	return 0;
}
