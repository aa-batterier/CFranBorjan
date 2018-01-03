#include "person.h"

#define STORLEK 100
#define FILNAMN "bil.b"

struct bil
{
	char regNr[STORLEK],fabrikat[STORLEK];
	int year,vikt,effekt;
	struct person *owner;
};
