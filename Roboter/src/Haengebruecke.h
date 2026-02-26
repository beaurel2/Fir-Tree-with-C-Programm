/*
 * Haengebruecke.h
 *
 *  Created on: 25.01.2025
 *      Author: beaur
 */

#ifndef HAENGEBRUECKE_H_
#define HAENGEBRUECKE_H_
#include <stdio.h>
#include "konstante.h"
#include "Balancebot.h"


struct Haengebruecke{
	char einzelfeld[MAXBREITE][MAXHOEHE];
	Balancebot* bb;
};
typedef struct Haengebruecke Haengebruecke;

void HaengebrueckeInit(Haengebruecke* hb){

	hb->bb = (Balancebot*)malloc(sizeof(Balancebot));
	BalanceBotInit(hb->bb);

	for(int y = 0; y < MAXHOEHE; y++){
		for(int x = 0; x < MAXBREITE; x++){
			if((y == 0) || (y == MAXHOEHE-1))
				hb->einzelfeld[x][y] = GELAENDER;
			else
				hb->einzelfeld[x][y] = HOLZ;
		}
	}
}

void HaengebrueckeCPrint(Haengebruecke* hb){
	for(int y = 0; y < MAXHOEHE; y++){
		for(int x = 0; x < MAXBREITE; x++){
			if((y == hb->bb->y) && (x == hb->bb->x)){
				printf("%c", hb->bb->symbol);
			}
			else
				printf("%c", hb->einzelfeld[x][y]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
}

void HaengebrueckeFPrint(Haengebruecke* hb , const char* dateiname, const char* modus){
	FILE* dateiSchreiben = fopen(dateiname, modus);
	if(dateiSchreiben == NULL){
		printf("Fehler bei der Datei\n");
	}

	for(int y = 0; y < MAXHOEHE; y++){
		for(int x = 0; x < MAXBREITE; x++){
			if((y == hb->bb->y) && (x == hb->bb->x)){
				fputc(hb->bb->symbol, dateiSchreiben);
			}
			else
				fputc(hb->einzelfeld[x][y], dateiSchreiben);
		}
		fputc('\n', dateiSchreiben);
	}

	fputc('\n', dateiSchreiben);
	fputc('\n', dateiSchreiben);

	fclose(dateiSchreiben);
}


#endif /* HAENGEBRUECKE_H_ */
