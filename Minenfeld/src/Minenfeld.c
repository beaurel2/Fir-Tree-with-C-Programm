/*
 ============================================================================
 Name        : Minenfeld.c
 Author      : beaurel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minenfeld.h"
#include "spielfeld.h"


int main(void)
{
	srand(time(NULL));


    minenfeld* pMF = (minenfeld*)malloc(sizeof(minenfeld));
    if(pMF == NULL){
    	return EXIT_FAILURE;
    }

	initMinenfeld(pMF);

	ausgabeMinenfeld(pMF);

	free(pMF);

	return 0;
}
