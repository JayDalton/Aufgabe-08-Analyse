/*###############################################################################
  Kodierung: UTF-8 ohne BOM
###############################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "vektoren.h"
#include "eingaben.h"
#include "generator.h"
#include "analysen.h"

#include "vektoren.c"
#include "eingaben.c"
#include "generator.c"
#include "analysen.c"

//###############################################################################
/**
  Das Programm dient der Analyse einer beliebig langen Liste zufälliger Ganz- 
  oder Gleitzahlen.

  @author Thomas Gerlach
  @version 1.0 
**/
//###############################################################################
int main(void)
{
  zufall_initialisieren();

  do {

    system("clear");
    printf("\n\n\tS t a t i s t i k\n\n");
    printf("Ich erzeuge ein Array mit zufälligen Zahlen aus dem Bereich von a bis b und werte es aus.\n\n");

    int auswahl = erfasse_ganzzahl("Soll es ein int-Array (1) oder ein double-Array (2) sein?", 1, 2);
    int anzahl = erfasse_ganzzahl("Bitte geben Sie die Länge des Arrays ein [2 - 1000]", 2, 1000);
    int minimum = erfasse_ganzzahl("Bitte geben Sie den Wert für a ein [-10000 - +10000]", -10000, 10000);
    int maximum = erfasse_ganzzahl("Bitte geben Sie den Wert für b ein [a – 50000]", minimum, 50000);

    int *liste_int = NULL;
    double *liste_dbl = NULL;

    //int liste_int[] = {31, 27, 54, 23, 19, 95, 29, 27, 64, 90, 97, 59};
    //anzahl = sizeof(liste_int) / sizeof(liste_int[0]);
    
    switch (auswahl) {

      case 1:
        liste_int = liste_ganzzahl_erstellen(anzahl);
        liste_ganzzahl_zufall_schreiben(liste_int, anzahl, minimum, maximum);
        liste_ganzzahl_matrix_ausgeben("Liste mit zufälligen Ganzzahlen", liste_int, anzahl, 12, 8);
        liste_ganzzahl_analysieren(liste_int, anzahl);
        free(liste_int);
        break;

      case 2:
        liste_dbl = liste_gleitzahl_erstellen(anzahl);
        liste_gleitzahl_zufall_schreiben(liste_dbl, anzahl, minimum, maximum);
        liste_gleitzahl_matrix_ausgeben("Liste mit zufälligen Gleitzahlen", liste_dbl, anzahl, 8, 10);
        liste_gleitzahl_analysieren(liste_dbl, anzahl);
        free(liste_dbl);
        break;
    }
    
  } while (erfasse_antwort("Noch einmal? (j/n)"));

  printf("\n\n\tAuf Wiedersehen!\n\n");
}
