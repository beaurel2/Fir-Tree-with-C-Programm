/*
 * Balancebot.h
 *
 *  Created on: 25.01.2025
 *      Author: beaur
 */

#ifndef BALANCEBOT_H_
#define BALANCEBOT_H_
#include <stdlib.h>
#include "konstante.h"

struct Balancebot
{
	int x;
	int y;
	char symbol;
};

typedef struct Balancebot Balancebot;

void BalanceBotInit(Balancebot* bb)
{
	bb->symbol = BOTSYMBOL;
	bb->x = 0;
	bb->y = MAXHOEHE/2;
}

void BalancebotBewege(Balancebot* bb, int richtung)
{
	switch(richtung){
	case HOCH :
		bb->y = bb->y - 1; break;
	case RUNTER :
		bb->y = bb->y + 1; break;
	default :
		bb->x = bb->x + 1 ;
	}
}

int BalancebotZufallsRichtung(const Balancebot* bb)
{
	int richtung = RECHTS;
	do
	{
		richtung = rand() % 10;
	}while(((bb->y == MAXHOEHE-2) && (richtung == RUNTER)) || ((bb->y == 1) && (richtung == HOCH)));

	return richtung;
}


#endif /* BALANCEBOT_H_ */
