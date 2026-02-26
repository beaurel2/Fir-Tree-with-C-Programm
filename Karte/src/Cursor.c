#include "Cursor.h"
#include <stdio.h>

//Positioniere Cursor an Position x,y
void cursor_bewegen(int x, int y)
{
	printf("\33[%d;%dH", y, x);	//Kommandos	\033[<L>; <C>H oder \033[<L>; <C>f
}
