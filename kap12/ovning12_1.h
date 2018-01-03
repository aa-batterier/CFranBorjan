#include "person.h"

#define STORLEK 100
struct bil
{
	char regNr[STORLEK],fabrikat[STORLEK];
	int year,vikt,effekt;
	struct person *owner;
};
