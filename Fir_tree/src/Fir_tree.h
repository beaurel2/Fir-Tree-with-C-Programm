/*
 * Fir_tree.h
 *
 *  Created on: 25.02.2026
 *      Author: beaur
 */

#ifndef FIR_TREE_H_
#define FIR_TREE_H_

#include <string.h>
#include <stdlib.h>
#include "Configuration.h"
#include "Cursor.h"


struct Fir_tree
{
 char bild[MAX_AUSDEHNUNG][MAX_AUSDEHNUNG];
 int breite;
 int hoehe;
};
typedef struct Fir_tree Fir_tree;


/* Aufgabe 1a */
Fir_tree* Fir_tree_generate(int breite, int hoehe)
{
	Fir_tree* neu_Fir_tree = (Fir_tree*)malloc(sizeof(Fir_tree));
	if(neu_Fir_tree == NULL){
		return NULL;
	}

	neu_Fir_tree->breite = (breite >= MAX_AUSDEHNUNG) ? MAX_AUSDEHNUNG - 1 : breite;
	neu_Fir_tree->hoehe  = (hoehe >= MAX_AUSDEHNUNG) ? MAX_AUSDEHNUNG - 1: hoehe;

	return neu_Fir_tree;
}
/* Aufgabe 1b */
void Fir_tree_init(Fir_tree* t_ptr)
{

	int spitze = (int)(t_ptr->breite/2.0);

	for(int i = 0; i < (t_ptr->hoehe - 2); i++){
		for(int j = 0; j <= (t_ptr->breite - 1); j++){
			if(j >= spitze - i && j <= spitze + i){
				//printf("%c", SYMBOL_NADEL);
				t_ptr->bild[i][j] = SYMBOL_NADEL;
			}
			else{
				//printf("%c", SYMBOL_LEER);
				t_ptr->bild[i][j] = SYMBOL_LEER;
			}
		}
		//printf("\n");
	}

    for(int i = t_ptr->hoehe - 2; i < t_ptr->hoehe; i++){
		for(int j = 0; j <= (t_ptr->breite-1); j++){
			if(j == spitze || j == spitze -1 || j == spitze + 1){
				//printf("%c", SYMBOL_STAMM);
				t_ptr->bild[i][j] = SYMBOL_STAMM;
			}
			else{
				//printf("%c", SYMBOL_LEER);
				t_ptr->bild[i][j] = SYMBOL_LEER;
			}
		}
		//printf("\n");
	}
}

/* Aufgabe 1c */
void Fir_tree_decorate(Fir_tree* t_ptr)
{

	for(int i = 0; i < MAX_AUSDEHNUNG; i++){
		for(int j = 0; j < MAX_AUSDEHNUNG; j++){
			if (t_ptr->bild[i][j] == SYMBOL_NADEL){
				int zahl = rand() % 7;
				if (zahl == 0){
					t_ptr->bild[i][j] = SYMBOL_KUGEL;
				}
			}
		}
		// printf("\n");
	}
}

/* Aufgabe 1d */
void Fir_tree_issue(Fir_tree* t_ptr)
{
    for(int i = 0; i < t_ptr->hoehe; i++){
    	for(int j = 0; j < t_ptr->breite; j++){
    		char element = t_ptr->bild[i][j];

    		if(element == SYMBOL_NADEL)
    		{
    			set_cursor_color(farben[GRUEN]);
    		}
    		else if(element == SYMBOL_KUGEL)
    		{
    			set_cursor_color(farben[ZUFALL]);
    		}
    		else if(element == SYMBOL_STAMM){
    			set_cursor_color(farben[BRAUN]);
    		}

    		cursor_draw_point(i + OFFSET, j + OFFSET, element);
    	}
    	printf("\n");
    }
}

#endif /* FIR_TREE_H_ */
