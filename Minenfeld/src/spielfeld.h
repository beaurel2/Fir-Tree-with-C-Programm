/*
 * spielfeld.h
 *
 *  Created on: 15.12.2024
 *      Author: beaur
 */

/* IHR CODE */


#ifndef SPIELFELD_H_
#define SPIELFELD_H_
#define TYP_MINE 10
#define TYP_WIESE 20
#define TYP_GRENZE 30
#define SYMBOL_MINE '*'
#define SYMBOL_WIESE ' '
#define SYMBOL_GRENZE '#'
#include <stdio.h>
#include <stdlib.h>

struct spielfeld
{
int x_koordinate;
int y_koordinate;
char typ;
};
typedef struct spielfeld spielfeld;


spielfeld* neuesSpielfeld(int y_koordinate, int x_koordinate, char typ)
{
	spielfeld* pSpielfeld = (spielfeld*) malloc (sizeof(spielfeld));
	if(pSpielfeld == NULL){
		return NULL;
	}

	pSpielfeld->typ = typ;
	pSpielfeld->x_koordinate = x_koordinate;
	pSpielfeld->y_koordinate = y_koordinate;

	return pSpielfeld;

}
void ausgabeSpielfeld(spielfeld* pSpielfeld)
{
	switch((int)pSpielfeld->typ)
	{
	    case TYP_GRENZE :
		    printf("%c\n", SYMBOL_GRENZE);
		    break;
	    case TYP_WIESE :
	    	printf("%c\n", SYMBOL_WIESE);
	    	break;
	    case TYP_MINE :
	    	printf("%c\n", SYMBOL_MINE);
	    	break;
	    default :
	    	printf("%d\n", pSpielfeld->typ);
	}
}


#endif
