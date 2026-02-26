#include <stdio.h>
#include "Console.h"
#include "Cursor.h"

//Leere Bildschirm, verstecke Cursor, Position 0,0
void console_init()
{
	console_leeren();
	console_verstecken();
}
//Leere Terminal
void console_leeren()
{
	printf("\33[2J");
}
//Verstecke Cursor
void console_verstecken()
{
	printf("\33[?25l");
}
//Zeigt den Cursor
void console_zeigen()
{
	printf("\33[?25h");
}

//Gebe Zeichen c an Position x, y aus.
void console_zeichne_punkt(int x, int y, char c)
{
	//printf("\33[%d;%dH%c", y, x, c);
	cursor_bewegen(x, y);
	printf("%c", c);
}


