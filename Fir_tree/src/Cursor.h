/*
 * Cursor.h
 *
 *  Created on: 25.02.2026
 *      Author: beaur
 */

#ifndef CURSOR_H_
#define CURSOR_H_
#include <stdio.h>


//Position the cursor at position x, y
void move_cursor(int x, int y)
{
	printf("\33[%d;%dH", y, x);   //Kommandos \033[<L>; <C>H or \033[<L>; <C>f
}

//Output character c at position x, y.
void cursor_draw_point(int x, int y, char c)
{
	move_cursor(x, y);
	printf("%c", c);
}

//Set text color or background color
void set_cursor_color(const char* color)
{
	printf("%s", color);
}

#endif /* CURSOR_H_ */
