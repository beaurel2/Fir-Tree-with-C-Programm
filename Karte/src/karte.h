/*
 * karte.h
 *
 *  Created on: 22.06.2024
 *      Author: beaur
 */

#ifndef KARTE_H_
#define KARTE_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "Console.h"
#include "Cursor.h"

struct Karte
{
	char symbole [5];
};
typedef struct Karte Karte;

Karte* Karte_erzeugen () {
	Karte* karte_ptr = (Karte*)malloc(sizeof(Karte));
	if(karte_ptr == NULL){
		printf("ACHTUNG - Kein Speicher!\n");
		return NULL;
	}

	return karte_ptr;
}

void Karte_init (Karte* karte_ptr) {
	if(karte_ptr != NULL){
		for(int i = 0; i < 5; i++){
			karte_ptr->symbole[i] = 'A' + i;
		}
	}
}

Karte* Karte_kopie (Karte* karte_ptr) {
	Karte* kopie_karte = Karte_erzeugen();
	if(karte_ptr == NULL){
		Karte_init(kopie_karte);
	}

	memcpy(&kopie_karte, &karte_ptr, sizeof(Karte));
	//strcpy(kopie_karte->symbole, karte_ptr->symbole);

	return kopie_karte;
}

char Karte_pruefe_symbol (Karte* karte_ptr, char c)
{
	if(karte_ptr == NULL)
	{
		return 0;
	}

	for(int i = 0; i < 5; i++){
		if(karte_ptr->symbole[i] == c){
			return c;
		}
	}

	return 0;
}

char Karte_vergleichen (Karte* karte1_ptr, Karte* karte2_ptr) {

	if((karte1_ptr == NULL) || (karte2_ptr == NULL))
		return 0;

	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			if(karte1_ptr->symbole[i] == karte2_ptr->symbole[j]){
				return karte1_ptr->symbole[i];
			}
		}
	}
	return 0;
}

void Karte_randomisieren (Karte* karte_ptr) {

	srand(time(NULL));

	for(int i = 0; i < 20; i++){
		int index1 = rand() % 5;
		int index2 = 0;
		do{
			index2 = rand() % 5;
		}while(index1 == index2);

		char tmp = karte_ptr->symbole[index1] ;
		karte_ptr->symbole[index1] = karte_ptr->symbole[index2] ;
		karte_ptr->symbole[index2] = tmp ;
	}
}

Karte* Karte_erzeuge_match (Karte* karte_ptr) {

	Karte* neu_Match_Karte = (Karte*)malloc(sizeof(Karte));
	if(neu_Match_Karte == NULL){
		return NULL;
	}

	for(int i = 0; i < 5; i++){
		neu_Match_Karte->symbole[i] = 'A' - 1;
	}

	neu_Match_Karte->symbole[0] = karte_ptr->symbole[0];

	for(int i = 1; i < 5; i++){
		char element = 'A' + (rand() % 26);

		if (!(Karte_pruefe_symbol(karte_ptr, element)) && !(Karte_pruefe_symbol(neu_Match_Karte, element)))
		{
			neu_Match_Karte->symbole[i] = element;
		}
	}

	Karte_randomisieren(neu_Match_Karte);

	return neu_Match_Karte;
}

void Karte_ausgeben_rand (int x, int y) {
	for(int i = 0 ; i < 9; i++){
		for(int j = 0; j < 11; j++){
			if(i == 0 || i == 8 || j == 0 || j == 10){
				console_zeichne_punkt(x + j , y + i, '#');
			}
			else{
				console_zeichne_punkt(x + j, y + i, ' ');
			}
		}
		//printf("\n");
	}
}


void Karte_ausgeben_inhalt (Karte* karte_ptr, int x, int y) {
	for(int i = 0 ; i < 9; i++){
		for(int j = 0; j < 11; j++){
			if(i == 0 || i == 8 || j == 0 || j == 10){
				console_zeichne_punkt(x + j , y + i, '#');
			}
			else if(j == 2 && i == 2){
				console_zeichne_punkt(x + j, y + i, karte_ptr->symbole[0]);
			}
			else if(j == 8 && i == 2){
				console_zeichne_punkt(x + j, y + i, karte_ptr->symbole[1]);
			}
			else if(j == 5 && i == 4){
				console_zeichne_punkt(x + j, y + i, karte_ptr->symbole[2]);
			}
			else if(j == 2 && i == 6){
				console_zeichne_punkt(x + j, y + i, karte_ptr->symbole[3]);
			}
			else if(j == 8 && i == 6){
				console_zeichne_punkt(x + j, y + i, karte_ptr->symbole[4]);
			}
			else{
				console_zeichne_punkt(x + j, y + i, ' ');
			}
		}
		printf("\n");
	}
}

void Karte_ausgeben (Karte* karte_ptr, int x, int y)
{
	Karte_randomisieren(karte_ptr);
	Karte_ausgeben_inhalt(karte_ptr, x, y);
}

#endif /* KARTE_H_ */
