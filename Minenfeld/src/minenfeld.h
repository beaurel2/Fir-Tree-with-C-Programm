/*
 * minenfeld.h
 *
 *  Created on: 15.12.2024
 *      Author: beaur
 */

/* IHR CODE */


#ifndef MINENFELD_H_
#define MINENFELD_H_
#include <stdio.h>
#include <stdlib.h>
#include "spielfeld.h"


#define X_GROESSE 20
#define Y_GROESSE 12

struct minenfeld
{
	struct spielfeld* gefahrengebiet[Y_GROESSE][X_GROESSE];
	int anzahlMinen;
};
typedef struct minenfeld minenfeld;


void initMinenfeld(minenfeld* pMinenfeld)
{
	for(int y = 0; y < Y_GROESSE; y++){
		for(int x = 0; x < X_GROESSE; x++){
			if(y==0 || y==(Y_GROESSE-1) || x==0 || x==(X_GROESSE-1)){
				pMinenfeld->gefahrengebiet[y][x]->typ = TYP_GRENZE;
			}
			else{
				pMinenfeld->gefahrengebiet[y][x]->typ = TYP_WIESE;
			}
			pMinenfeld->gefahrengebiet[y][x]->x_koordinate = x;
			pMinenfeld->gefahrengebiet[y][x]->y_koordinate = y;
		}
	}

}
void ausgabeMinenfeld(minenfeld* pMinenfeld)
{
	for(int y=0; y<Y_GROESSE; y++){
		for(int x=0; x<X_GROESSE; x++){
			ausgabeSpielfeld(pMinenfeld->gefahrengebiet[y][x]);
		}
		printf("\n");
	}
}

int myRand(int max)
{
	return ( (rand() % (max-2)) + 1 );
}

void platziereMinen(minenfeld* pMinenfeld, int anzahlMinen, int seed)
{
	srand(seed);

	int plaziert = 0;

	while(plaziert < anzahlMinen){
		int x = myRand(anzahlMinen);
		int y = myRand(anzahlMinen);

		if((pMinenfeld->gefahrengebiet[y][x]->typ != TYP_WIESE) && (pMinenfeld->gefahrengebiet[y][x]->typ != TYP_MINE)){
			pMinenfeld->gefahrengebiet[y][x]->typ = TYP_MINE;
			plaziert++;
		}
	}
}

void pruefeNachbarn(minenfeld* pMinenfeld, spielfeld* pSpielfeld)
{
	int y, x;
	if(pSpielfeld->typ == TYP_WIESE){
		pSpielfeld->x_koordinate = SYMBOL_MINE;
		pSpielfeld->y_koordinate = SYMBOL_MINE;

		pMinenfeld->anzahlMinen++;
	}

	if(pMinenfeld->anzahlMinen > 0){
		pMinenfeld->anzahlMinen = pSpielfeld->typ;
	}
	else if(pMinenfeld->anzahlMinen == 0 || pMinenfeld->gefahrengebiet[y][x]->typ != (char)TYP_WIESE){  // 0 oder NULL
	}
}
void berechneGefahrengebiet(minenfeld* pMinenfeld){

	for(int y=0; y < Y_GROESSE; y++){
		for(int x=0; x < X_GROESSE; x++){
			pruefeNachbarn(pMinenfeld, (spielfeld*)pMinenfeld);
		}
	}
}
minenfeld* neuesMinenfeld(int anzahlMinen, int seed)
{
	minenfeld* neu_minenfeld = (minenfeld*)malloc(sizeof(minenfeld));
	if(neu_minenfeld == NULL){
		return NULL;
	}

	initMinenfeld(neu_minenfeld);
	platziereMinen(neu_minenfeld, anzahlMinen, seed);
	berechneGefahrengebiet(neu_minenfeld);

	return neu_minenfeld;
}



#endif
