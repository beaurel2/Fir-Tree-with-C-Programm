/*
 ============================================================================
 Name        : Roboter.c
 Author      : beaurel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "konstante.h"
#include "Haengebruecke.h"



int main(void)
{
	Haengebruecke* hb = (Haengebruecke*)malloc(sizeof(Haengebruecke));
    HaengebrueckeInit(hb);
    while(hb->bb->x <= MAXBREITE-1){
    	HaengebrueckeCPrint(hb);
    	HaengebrueckeFPrint(hb , "bruecke.txt", "a+");
    	BalancebotBewege(hb->bb, BalancebotZufallsRichtung((const)hb->bb));
    }

    free(hb);

    return 0;
}
