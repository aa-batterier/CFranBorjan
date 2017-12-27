#include <stdio.h>

#define N 9

_Bool kolumn_kontroll(int p_f[N][N])
{
	/*Kolumn. Kollar så att varje kolumn inte har samma siffra.*/
	for (int b = 0; b < N; b++) /*Loopar till nästa kolummn.*/
		for (int a = 0; a < N; a++) /*Loopar mellan varje plats i kolumnen i p_f.*/
			for (int c = 0; c < N; c++) /*Kollar varje plats mot första platsen sen samma sak mot andra osv.*/
			{
				if (a == c) /*Dumt att jämföra samma plats mot sig själv.*/
					continue;
				else if (p_f[a][b] == p_f[c][b]) /*Kollar så att varje siffra i varje kolumn är unik.*/
					return 0; /*Om de är lika retunera fel.*/
			}
	return 1;
}

_Bool rad_kontroll(int p_f[N][N])
{
	/*Kontrollera att varje rad i p_f inte har samma siffra.*/
	for (int a = 0; a < N; a++) /*Loopar till nästa rad.*/
		for (int b = 0; b < N; b++) /*Loopar mellan varje plats i raden i p_f.*/
			for (int c = 0; c < N; c++) /*Kollar varje plats mot första platsen sen samma sak mot andra osv.*/
			{
				if (b == c) /*Dumt att jämföra samma plats mot sig själv.*/
					continue;
				else if (p_f[a][b] == p_f[a][c]) /*Kollar så att varje siffra i varje rad är unik.*/
					return 0; /*Om de är lika returnera fel.*/
			}
	return 1;
}

_Bool region_kontroll(int p_f[N][N])
{
	/*Region.
	 *Gör om varje region till ett fält pga. lättare att jämföra platsernas värden i fält än regioner.*/
	int i=0,j=0,k=0,m=0;
	int r_f[N][N]; /*Regionens fält, ny rad för varje region.*/
	for (int a = 0; a < 3; a++) /*Tre rutor vertikalt (rad).*/
	{
		for (int b = 0; b < 3; b++) /*Tre rutar plant (kolumn).*/
		{
			i = a*3; /*Sätter i till a*3 pga. nästa region till höger bilr noll(0*3), dock inte regionerna under har start värde 3(1*3) och 6(2*3).*/
			m = 0; /*Återställer m pga. nästa rad i r_f.*/
			for (int c = 0; c < 3; c++) /*Tre rutor inuti regionen vertikalt.*/
			{
				j = b*3; /*Sätter j till b*3 pga. nästa region till höger bilr start värde 3(1*3) och 6(2*3), dock regionen rakt under blir återigen noll.*/
				for (int d = 0; d < 3; d++) /*Tre rutor inuti regionen plant.*/
				{
					r_f[k][m] = p_f[i][j];
					j++; /*Ökar j för att hoppa till nästa plats i raden i.*/
					m++; /*Ökar m för att hoppa till nästa plats i raden k.*/
				}
				i++; /*Ökar i för att hoppa till nästa rad i regionen.*/
			}
			k++; /*Ökar till en ny rad i r_f pga. ny region.*/
		}
	}
	/*Kontrollerar så att varje plats värde är unik i varje region.*/
	return rad_kontroll(r_f);
}

_Bool sudoku_kontroll(int p_f[N][N])
{
	if (kolumn_kontroll(p_f) && rad_kontroll(p_f) && region_kontroll(p_f))
		return 1;
	return 0;
}

int main(void)
{
	int p_f_solved[N][N] = {{2,9,5,7,4,3,8,6,1},{4,3,1,8,6,5,9,2,7},{8,7,6,1,9,2,5,4,3},{3,8,7,4,5,9,2,1,6},{6,1,2,3,8,7,4,9,5},{5,4,9,2,1,6,7,3,8},{7,6,3,5,3,4,1,8,9},{9,2,8,6,7,1,3,5,4},{1,5,4,9,3,8,6,7,2}},p_f_failed[N][N] = {{2,9,5,7,4,9,8,6,1},{4,3,1,8,6,5,9,2,4},{8,1,6,1,9,2,5,4,3},{5,8,7,4,5,9,2,1,6},{6,1,2,3,3,7,4,9,5},{5,4,9,2,1,6,7,3,8},{7,6,3,5,3,4,1,5,9},{9,2,8,6,7,1,3,5,4},{1,5,1,9,3,8,6,7,2}};
	/*Tester.*/
	printf("Korrekt sudoku: ");
	if (sudoku_kontroll(p_f_solved))
		printf("Stämmer.\n");
	else
		printf("Stämmer inte.\n");
	printf("Felaktigt sudoku: ");
	if (!sudoku_kontroll(p_f_failed))
		printf("Stämmer.\n");
	else
		printf("Stämmer inte.\n");
	return 0;
}
