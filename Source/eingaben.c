//###############################################################################
/** 
  Leert den Puffer der Standard-Eingabe.
**/
//###############################################################################
void puffer_leeren(void)
{
  while (getchar() != '\n')
  ;
}

//###############################################################################
/** 
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer ganzen Zahl zwischen zwei gegebenen Grenzen auf.
  
  @param  titel Beschriftung der Eingabeaufforderung  
  @param  minimum Minimum des definierten Wertebereiches
  @param  maximum Maximum des definierten Wertebereiches

  @return Die im Wertebereich definierte Ganzzahl
**/
//###############################################################################
int erfasse_ganzzahl(const char *titel, int minimum, int maximum)
{
  int ergebnis = 0;

  printf("\n%s: ", titel);

  while (scanf("%d%*[^\n]", &ergebnis) == 0 || (ergebnis < minimum || maximum < ergebnis)) 
  {
    printf("\nBitte Werte von '%i' bis '%i' eingeben: ", minimum, maximum);
    puffer_leeren();
  }

  puffer_leeren();

  return ergebnis;
}

//###############################################################################
/** 
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer Liste ganzer Zahlen zwischen zwei gegebenen Grenzen auf.
  
  @param  titel   Beschriftung der Eingabeaufforderung  
  @param  anzahl  Anzahl der zu erfassenden Werte
  @param  minimum Minimum des definierten Wertebereiches
  @param  maximum Maximum des definierten Wertebereiches

  @return Zeiger auf erfasste Liste
**/
//###############################################################################
int *liste_ganzzahl_werte_erfassen(const char *titel, int anzahl, int minimum, int maximum)
{
  char puffer[20 + strlen(titel)];
  int *liste = liste_ganzzahl_erstellen(anzahl);

  for (int i = 0; i < anzahl; i++) {
    sprintf(puffer, "%s Wert %d", titel, i + 1);
    *(liste + i) = erfasse_ganzzahl(puffer, minimum, maximum);
  }

  return liste;  
}

//###############################################################################
/** 
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer Matrix ganzer Zahlen zwischen zwei gegebenen Grenzen auf.
  
  @param  titel   Beschriftung der Eingabeaufforderung  
  @param  zeilen  Anzahl der Zeilen
  @param  spalten Anzahl der Spalten
  @param  minimum Minimum des definierten Wertebereiches
  @param  maximum Maximum des definierten Wertebereiches

  @return Zeiger auf erfasste Liste
**/
//###############################################################################
int *matrix_ganzzahl_werte_erfassen(const char *titel, int zeilen, int spalten, int minimum, int maximum)
{
  char puffer[20];
  int *liste = liste_ganzzahl_erstellen(zeilen * spalten);

  printf("\n%s", titel);
  
  for (int zeile = 0; zeile < zeilen; zeile++) {
    sprintf(puffer, "Zeile %d", zeile + 1);
    int *daten = liste_ganzzahl_werte_erfassen(puffer, spalten, minimum, maximum);
    liste_ganzzahl_werte_kopieren(daten, spalten, liste + (zeile * spalten));
    free(daten);
  }

  return liste;
}

//###############################################################################
/** 
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer Gleitkommazahl zwischen zwei gegebenen Grenzen auf.

  @param  titel Beschriftung der Eingabeaufforderung  
  @param  minimum Minimum des definierten Wertebereiches
  @param  maximum Maximum des definierten Wertebereiches

  @return Die im Wertebereich definierte Gleitkommazahl.
*/
//###############################################################################
double erfasse_gleitzahl(const char *titel, double minimum, double maximum)
{
  double ergebnis = 0;

  printf("\n%s: ", titel);

  while (scanf("%lf%*[^\n]", &ergebnis) == 0 || (ergebnis < minimum || maximum < ergebnis)) 
  {
    printf("\nBitte Werte von '%.2lf' bis '%.2lf' eingeben: ", minimum, maximum);
    puffer_leeren();
  }

  puffer_leeren();

  return ergebnis;
}

//###############################################################################
/** 
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer Auswahl zwischen j/J und n/N auf.

  @param  titel Beschriftung der Eingabeaufforderung  

  @return Liefert 1 für Zustimmung und 0 für Ablehnung
*/
//###############################################################################
int erfasse_antwort(const char *titel)
{
  char *eingabe = (char *) calloc(10, sizeof(char));

  printf("\n%s: ", titel);

  while (scanf("%1s[jJnN]%*[^\n]", eingabe) == 0)
  {
    printf("\nBitte nur 'j' oder 'n' eingeben.\n");
    puffer_leeren();
  }
  
  puffer_leeren();

  return eingabe[0] == 'j' || eingabe[0] == 'J' ? 1 : 0;
}

//###############################################################################
/** 
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer Zeichenketten mit einer anzugebenen maximalen 
  Länge.

  @param  titel Beschriftung der Eingabeaufforderung  
  @param  maximum Maximale Länge der Eingabe

  @return Liefert Zeiger auf die erfasst Zeichenkette
*/
//###############################################################################
char *erfasse_zeichen(char *titel, unsigned int maximum)
{
  char format[20];
  char *eingabe = (char *) calloc(maximum + 1, sizeof(char));

  sprintf(format, "%%%d[^\n]", maximum); // "%10[^\n]"

  printf("\n\n%s : ", titel);

  scanf(format, eingabe);
  
  puffer_leeren();
  
  return eingabe;
}

