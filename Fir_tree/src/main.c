/*
 ============================================================================
 Name        : Fir_tree.c
 Author      : beaurel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Fir_tree.h"
#include "Configuration.h"


int main(void) {
	srand(time(NULL));
	puts("Oh Tannenbau, oh Tannenbaum!\n");

	printf("Begin\n");


	Fir_tree* t_ptr = Fir_tree_generate(29, 15);

	if (!t_ptr) return EXIT_FAILURE;

	Fir_tree_init(t_ptr);
	Fir_tree_decorate(t_ptr);
	Fir_tree_issue(t_ptr);
	free(t_ptr);

	return EXIT_SUCCESS;
}
