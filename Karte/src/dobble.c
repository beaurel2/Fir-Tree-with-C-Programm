/*
 * dobble.c
 *
 *  Created on: 22.06.2024
 *      Author: beaur
 */

#include <stdio.h>
#include <stdlib.h>

#include "cursor.h"
#include "karte.h"


#ifdef _WIN32
#include <windows.h>    // Sleep
#else
#include <time.h>       // nanosleep
#endif

void Dobble_pause() {
#ifdef _WIN32
    Sleep(2000); // 2 secondes
#else
    struct timespec zeit;
    zeit.tv_sec = 2;
    zeit.tv_nsec = 0;
    nanosleep(&zeit, NULL);
#endif
}

Karte* karte1_ptr;
Karte* karte2_ptr;
time_t startzeit;
int treffer;
char eingabe;

void Dobble_erzeugen()
{
	if (karte1_ptr != NULL)
		free(karte1_ptr);
	if (karte2_ptr != NULL)
		free(karte2_ptr);
	karte1_ptr = Karte_erzeugen();
	Karte_init(karte1_ptr);
	Karte_randomisieren(karte1_ptr);

	karte2_ptr = Karte_erzeuge_match (karte1_ptr);
	free(karte1_ptr);
	karte1_ptr = Karte_erzeuge_match (karte2_ptr);
	Karte_randomisieren(karte2_ptr);
}

void Dobble_ausgeben() {

    Karte_ausgeben(karte1_ptr, 5, 3);
	Karte_ausgeben(karte2_ptr, 20, 3);
}

void Dobble_ergebnis() {

	cursor_bewegen(5, 14);

	startzeit = time(NULL);
	Karte_init(karte1_ptr);
	Karte_init(karte2_ptr);

	Karte_randomisieren(karte1_ptr);
	Karte_randomisieren(karte2_ptr);

	char Karte1_eingabe = Karte_pruefe_symbol (karte1_ptr, eingabe);
	char Karte2_eingabe = Karte_pruefe_symbol (karte2_ptr, eingabe);

	if(time(NULL) - startzeit > 30){
		printf("Antwort zu spät!!!\n");
		return; 
	}

	if(Karte1_eingabe && Karte2_eingabe){
		printf("Richtige Antwort !!!\n");
		treffer++;
	}
	else{
		printf("Falsche Antwort !!! => Richtige Antwort: %c \n", Karte_vergleichen (karte1_ptr, karte2_ptr));
	}

	printf("\n");
	printf("Richtige Antwort\n");

}

int mainXD(void)
{
	remove("main()");
	rename("mainXD()", "main()");
return EXIT_SUCCESS;
}

void print_karte(Karte* karte_ptr){
	if(karte_ptr == NULL){
		printf("\nKarte is NULL Pointer\n");
	}
	printf("Meine Karte: ");
	for(int i=0; i < 5; i++){
		printf("%c ", karte_ptr->symbole[i]);
	}
	printf("\n");
}

int main(void)
{
	karte1_ptr = Karte_erzeugen();
	karte2_ptr = Karte_erzeugen();

	time_t zeit = 30 - time(NULL) + startzeit;

	srand(time(NULL));
	startzeit = time(NULL);
	do {
		console_leeren();				//Restzeit ausgeben
		cursor_bewegen(20, 1);
		printf("Restzeit: %ld Sekunden", zeit);

		Dobble_erzeugen();
		Dobble_ausgeben();

				//Einlesen
		cursor_bewegen(5, 13);
		printf("\nBitte geben Sie den übereinstimmenden Buchstaben ein: ");
		eingabe = getchar();

			//Enter entfernen
	    // while(eingabe == '\n')
		// eingabe = getchar();

				//Ergebnis ausgeben
	    Dobble_ergebnis();

				//Zwei Sekunden Warten
		//Dobble_pause();
	} while (time(NULL) - startzeit < 30);
	console_leeren();
	cursor_bewegen(5, 2);
	printf("Herzlichen Glückwunsch! Das waren %i Treffer !!!\n", treffer);
	/*Dobble_pause();
	Dobble_pause();
	Dobble_pause();
	Dobble_ergebnis();
	//getchar();
	Dobble_pause();*/

	// Speicher freigeben
	if (karte1_ptr != NULL){
		//printf("\nSpeicher freigeben!\n");
		free(karte1_ptr);
	}
	if (karte2_ptr != NULL){
		free(karte2_ptr);
	}

	return EXIT_SUCCESS;
}
