//###############################################################################
/** 
  Erstellt eine Liste von Ganzzahlen (Integer) mittels übergebener Länge

  @param  anzahl  Länge der zu erstellenden Ganzzahl-Liste
  
  @return Zeiger auf erstellte Liste
**/
//###############################################################################
int *liste_ganzzahl_erstellen(int anzahl)
{
  return (int *) calloc(anzahl, sizeof(int));
}

//###############################################################################
/** 
  Erstellt eine Liste von Gleitzahlen (Double) mittels übergebener Länge

  @param  anzahl  Länge der zu erstellenden Gleitzahl-Liste
  
  @return Zeiger auf erstellte Liste
**/
//###############################################################################
double *liste_gleitzahl_erstellen(int anzahl)
{
  return (double *) calloc(anzahl, sizeof(double));
}

//###############################################################################
/** 
  Erstellt eine Liste von Symbolen (Char) mittels übergebener Länge

  @param  anzahl  Länge der zu erstellenden Symbol-Liste
  
  @return Zeiger auf erstellte Liste
**/
//###############################################################################
char *liste_symbole_erstellen(int anzahl)
{
  return (char *) calloc(anzahl + 1, sizeof(char));
}

//###############################################################################
/** 
  Schreibt den übergebenen Wert in die/den mittels Zeiger übergebene Ganzzahl-
  Liste/Bereich
  
  @param  liste   Zeiger auf Liste
  @param  anzahl  Anzahl der Elemente in der Liste
  @param  wert    Der zu schreibende Wert
  
  @return Zeiger auf die Liste
**/
//###############################################################################
int *liste_ganzzahl_werte_schreiben(int *liste, int anzahl, int wert)
{
  for (int *p = liste; p < (liste + anzahl); p++) {
    *p = wert;
  }

  return liste;
}

//###############################################################################
/** 
  Schreibt den übergebenen Wert in die/den mittels Zeiger übergebene Gleitzahl-
  Liste/Bereich
  
  @param  liste   Zeiger auf Liste
  @param  anzahl  Anzahl der Elemente in der Liste
  @param  wert    Der zu schreibende Wert
  
  @return Zeiger auf die Liste
**/
//###############################################################################
double *liste_gleitzahl_werte_schreiben(double *liste, int anzahl, double wert)
{
  for (double *p = liste; p < (liste + anzahl); p++) {
    *p = wert;
  }

  return liste;
}

//###############################################################################
/** 
  Schreibt den übergebenen Wert in die/den mittels Zeiger übergebene Ganzzahl-
  Liste/Bereich
  
  @param  liste   Zeiger auf Liste
  @param  anzahl  Anzahl der Elemente in der Liste
  
  @return Zeiger auf die Liste
**/
//###############################################################################
int liste_ganzzahl_summe(int *liste, int anzahl)
{
  int summe = 0;
  for (int *p = liste; p < (liste + anzahl); p++) {
    summe += *p;
  }
  return summe;
}
  
//###############################################################################
/** 
  Ermittelt die Position des maximalen Element der übergebenen Liste
  
  @param  liste   Zeiger auf Liste
  @param  anzahl  Anzahl der Elemente in der Liste
  
  @return Zeiger auf maximales Element der Liste
**/
//###############################################################################
int *liste_ganzzahl_maximum(int *liste, int anzahl)
{
  int *max = liste;
  for (int *p = liste; p < (liste + anzahl); p++) {
    if (*p > *max) {
      max = p;
    }
  }
  return max;
}

//###############################################################################
/** 
  Ermittelt die Position des minimalen Element der übergebenen Liste
  
  @param  liste   Zeiger auf Liste
  @param  anzahl  Anzahl der Elemente in der Liste
  
  @return Zeiger auf minimales Element der Liste
**/
//###############################################################################
int *liste_ganzzahl_minimum(int *liste, int anzahl)
{
  int *min = liste;
  for (int *p = liste; p < (liste + anzahl); p++) {
    if (*p < *min) {
      min = p;
    }
  }
  return min;
}

//###############################################################################
/** 
  Ermittelt die Position des maximalen Element der übergebenen Liste
  
  @param  liste   Zeiger auf Liste
  @param  anzahl  Anzahl der Elemente in der Liste
  
  @return Zeiger auf maximales Element der Liste
**/
//###############################################################################
double *liste_gleitzahl_maximum(double *liste, int anzahl)
{
  double *max = liste;
  for (double *p = liste; p < (liste + anzahl); p++) {
    if (*p > *max) {
      max = p;
    }
  }
  return max;
}

//###############################################################################
/** 
  Ermittelt die Position des minimalen Element der übergebenen Liste
  
  @param  liste   Zeiger auf Liste
  @param  anzahl  Anzahl der Elemente in der Liste
  
  @return Zeiger auf minimales Element der Liste
**/
//###############################################################################
double *liste_gleitzahl_minimum(double *liste, int anzahl)
{
  double *min = liste;
  for (double *p = liste; p < (liste + anzahl); p++) {
    if (*p < *min) {
      min = p;
    }
  }
  return min;
}

//###############################################################################
/** 
  Ermittelt die Existenz eines Wertes in der übergebenen Liste
  
  @param  von   Zeiger auf den Beginn der/des Liste/Bereiches
  @param  bis   Zeiger auf das Ende der/des Liste/Bereiches
  @param  wert  der zu suchende Wert
  
  @return Zeiger auf maximales Element der Liste
**/
//###############################################################################
int liste_ganzzahl_wert_existenz(int *von, int *bis, int wert)
{
  int *nadel = von;
  for (int *p = von; p < bis && wert != *nadel; p++) {
    if (*p == wert) {
      nadel = p;
    }
  }
  return wert == *nadel ? 1 : 0;
}

//###############################################################################
/** 
  Ermittelt die Position eines Wertes in der übergebenen Liste
  
  @param  von   Zeiger auf den Beginn der/des Liste/Bereiches
  @param  bis   Zeiger auf das Ende der/des Liste/Bereiches
  @param  wert  der zu suchende Wert
  
  @return Zeiger auf maximales Element der Liste
**/
//###############################################################################
int *liste_ganzzahl_wert_position(int *von, int *bis, int wert)
{
  int *nadel = von;
  for (int *p = von; p < bis && wert != *nadel; p++) {
    if (*p == wert) {
      nadel = p;
    }
  }
  return wert == *nadel ? nadel : NULL;
}

//###############################################################################
/** 
  Erstellt eine Zusammenstellung aller Werte einer Liste im Bereich von min / max
  
  @param  liste   die zu durchsuchende Liste
  @param  anzahl  Anzahl der Werte in der Liste
  @param  min     Untere Grenze
  @param  max     Obere Grenze
  @param  result  Ergebnisliste
  
  @return Anzahl der gefundenen Werte
**/
//###############################################################################
int liste_gleitzahl_werte_filtern(double *liste, int anzahl, double min, double max, double *result)
{
  int summe = 0;
  int index = 0;

  for (int i = 0; i < anzahl; i++) {
    if (min <= liste[i] && liste[i] <= max) {
      result[index++] = liste[i];
      summe++;
    }
  }
  
  return summe;
}

//###############################################################################
/** 
  Erstellt eine Zusammenstellung der Indizes aller Werte einer Liste im Bereich 
  von min / max
  
  @param  liste   die zu durchsuchende Liste
  @param  anzahl  Anzahl der Werte in der Liste
  @param  min     Untere Grenze
  @param  max     Obere Grenze
  @param  result  Ergebnisliste
  
  @return Anzahl der gefundenen Werte
**/
//###############################################################################
int liste_gleitzahl_werte_indizes(double *liste, int anzahl, double min, double max, int *result)
{
  int summe = 0;
  int index = 0;

  for (int i = 0; i < anzahl; i++) {
    if (min <= liste[i] && liste[i] <= max) {
      result[index++] = i;
      summe++;
    }
  }
  
  return summe;
}

//###############################################################################
/** 
  Kopiert die mittels Zeiger übergebene Ganzzahl-Liste
  
  @param  liste   Zeiger auf die Quell-Liste
  @param  anzahl  Länge der zu erstellenden Symbol-Liste
  
  @return Zeiger auf die als Kopie erstellte Liste
**/
//###############################################################################
int *liste_ganzzahl_kopieren(int *liste, int anzahl)
{
  int *kopie = liste_ganzzahl_erstellen(anzahl);
  
  for (int i = 0; i < anzahl; i++) {
    kopie[i] = liste[i];
  }
  
  return kopie;
}

//###############################################################################
/** 
  Kopiert die mittels Zeiger übergebene Ganzzahl-Liste
  
  @param  liste1  Zeiger auf die Quell-Liste
  @param  anzahl  Länge der zu erstellenden Symbol-Liste
  @param  liste2  Zeiger auf die Quell-Liste
**/
//###############################################################################
void liste_ganzzahl_werte_kopieren(int *liste1, int anzahl, int *liste2)
{
  for (int i = 0; i < anzahl; i++) {
    *(liste2 + i) = *(liste1 + i);
  }
}

//###############################################################################
/** 
  Kopiert die mittels Zeiger übergebene Gleitzahl-Liste
  
  @param  liste   Zeiger auf die Quell-Liste
  @param  anzahl  Länge der zu erstellenden Symbol-Liste
  
  @return Zeiger auf die als Kopie erstellte Liste
**/
//###############################################################################
double *liste_gleitzahl_kopieren(double *liste, int anzahl)
{
  double *kopie = liste_gleitzahl_erstellen(anzahl);
  
  for (int i = 0; i < anzahl; i++) {
    kopie[i] = liste[i];
  }
  
  return kopie;
}

//###############################################################################
/** 
  Kopiert die mittels Zeiger übergebene Symbol-Liste
  
  @param  liste   Zeiger auf die Quell-Liste
  @param  anzahl  Länge der zu erstellenden Symbol-Liste
  
  @return Zeiger auf die als Kopie erstellte Liste
**/
//###############################################################################
char *liste_symbole_kopieren(char *liste, int anzahl)
{
  char *kopie = liste_symbole_erstellen(anzahl);
  
  for (int i = 0; i < anzahl; i++) {
    kopie[i] = liste[i];
  }
  
  return kopie;
}

//###############################################################################
/** 
  Berechnet die Varianz (Statistik) der mittels Zeiger übergebenen Ganzzahl-Liste
  
  @param  liste   Zeiger auf die Quell-Liste
  @param  anzahl  Länge der zu erstellenden Symbol-Liste
  @param  schnitt Der bereits berechnete Durchschnitt aller Elemente der Liste
  
  @return Zeiger auf die als Kopie erstellte Liste
**/
//###############################################################################
double liste_ganzzahl_varianz_berechnen(int *liste, int anzahl, double schnitt)
{
  double varianz = 0;

  for (int i = 0; i < anzahl; i++) {
    varianz += pow(fabs(liste[i] - schnitt), 2);
  }

  return varianz / (anzahl - 1);
}

//###############################################################################
/** 
  Berechnet die Varianz (Statistik) der mittels Zeiger übergebenen Gleitzahl-Liste
  
  @param  liste   Zeiger auf die Quell-Liste
  @param  anzahl  Länge der zu erstellenden Symbol-Liste
  @param  schnitt Der bereits berechnete Durchschnitt aller Elemente der Liste
  
  @return Zeiger auf die als Kopie erstellte Liste
**/
//###############################################################################
double liste_gleitzahl_varianz_berechnen(double *liste, int anzahl, double schnitt)
{
  double varianz = 0;

  for (int i = 0; i < anzahl; i++) {
    varianz += pow(fabs(liste[i] - schnitt), 2);
  }

  return varianz / (anzahl - 1);
}

//###############################################################################
/** 
  eigene Quick-Sort-Funktion ???
**/
//###############################################################################
int ganzzahl_vergleichen(const void *a, const void *b)
{
  return ( *(int *)a - *(int *)b );
}

//###############################################################################
/** 
  eigene Quick-Sort-Funktion ???
**/
//###############################################################################
int gleitzahl_vergleichen(const void *a, const void *b)
{
  return ( *(double *)a - *(double *)b );
}

//###############################################################################
/** 
  Sortiert die mittels Zeiger übergebene Ganzzahl-Liste aufsteigend
  
  @param  liste   Zeiger auf die Liste
  @param  anzahl  Länge der Liste
  
  @return Zeiger auf die sortierte Liste
**/
//###############################################################################
void liste_ganzzahl_sortieren(int *liste, int anzahl)
{
  qsort(liste, anzahl, sizeof(int), ganzzahl_vergleichen);
}

//###############################################################################
/** 
  Sortiert die mittels Zeiger übergebene Gleitzahl-Liste aufsteigend
  
  @param  liste   Zeiger auf die Liste
  @param  anzahl  Länge der Liste
  
  @return Zeiger auf die sortierte Liste
**/
//###############################################################################
void liste_gleitzahl_sortieren(double *liste, int anzahl)
{
  qsort(liste, anzahl, sizeof(double), gleitzahl_vergleichen);
}

//###############################################################################
/** 
  Berechnet den Median (Statistik) der mittels Zeiger übergebenen Ganzzahl-Liste
  
  @param  liste  Zeiger auf die Liste
  @param  anzahl  Länge der Liste
  
  @return Der berechnete Median
**/
//###############################################################################
double liste_ganzzahl_median_berechnen(int *liste, int anzahl)
{
  double median = 0;
  int *kopie = liste_ganzzahl_kopieren(liste, anzahl);
  
  liste_ganzzahl_sortieren(kopie, anzahl);

  if (anzahl % 2 != 0) {
    
    median = kopie[(anzahl - 1) / 2];

  } else {

    median = kopie[anzahl / 2 - 1];
    median += kopie[anzahl / 2];
    median /= 2;
    
  }
  
  free(kopie);

  return median;
}

//###############################################################################
/** 
  Berechnet den Median (Statistik) der mittels Zeiger übergebenen Gleitzahl-Liste
  
  @param  liste  Zeiger auf die Liste
  @param  anzahl  Länge der Liste
  
  @return Der berechnete Median
**/
//###############################################################################
double liste_gleitzahl_median_berechnen(double *liste, int anzahl)
{
  double median = 0;
  double *kopie = liste_gleitzahl_kopieren(liste, anzahl);

  liste_gleitzahl_sortieren(kopie, anzahl);

  if (anzahl % 2 != 0) {
    
    median = kopie[(anzahl - 1) / 2];

  } else {

    median = kopie[anzahl / 2 - 1];
    median += kopie[anzahl / 2];
    median /= 2;
    
  }

  free(kopie);

  return median;
}

//###############################################################################
/** 
  Schreibt die mittels Zeiger übergebene Liste als Vektor in die Standard-Ausgabe
  
  @param  liste   Zeiger auf die Liste
  @param  anzahl  Länge der Liste
  @param  kleber  Trennzeichen zwischen den einzelnen Elementen der Liste
  @param  breite  Anzeigebreite der Elemente im Vektor
**/ 
//###############################################################################
void liste_ganzzahl_vektor_ausgeben(int *liste, int anzahl, char *kleber, int breite)
{
  for (int i = 0; i < anzahl; i++)
  {
    printf("%*d%s", breite, liste[i], (i < anzahl - 1) ? kleber : "");
  }
}

//###############################################################################
/** 
  Schreibt die mittels Zeiger übergebene Liste als Matrix in die Standard-Ausgabe
  
  @param  titel   Beschreibung der Liste
  @param  liste   Zeiger auf die Liste
  @param  anzahl  Länge der Liste
  @param  spalten Anzahl der Spalten in der Matrix
  @param  breite  Breite der Spalten in der Matrix
**/
//###############################################################################
void liste_ganzzahl_matrix_ausgeben(const char *titel, int *liste, int anzahl, int spalten, int breite)
{
  printf("\n%s\n", titel);
  for (int i = 0; i < anzahl; )
  {
    for (int j = 0; j < spalten && i < anzahl; j++)
    {
      printf("%*d", breite, liste[i++]);
    }
    printf("\n");
  }
}

//###############################################################################
/** 
  Schreibt die mittels Zeiger übergebene Liste als Vektor in die Standard-Ausgabe
  
  @param  liste   Zeiger auf die Liste
  @param  anzahl  Länge der Liste
  @param  kleber  Trennzeichen zwischen den einzelnen Elementen der Liste
  @param  breite  Anzeigebreite der Elemente im Vektor
**/
//###############################################################################
void liste_gleitzahl_vektor_ausgeben(double *liste, int anzahl, char *kleber, int breite)
{
  for (int i = 0; i < anzahl; i++)
  {
    printf("%*lf%s", breite, liste[i], (i < anzahl - 1) ? kleber : "");
  }
}

//###############################################################################
/** 
  Schreibt die mittels Zeiger übergebene Liste mit Titel in die Standard-Ausgabe
  
  @param  titel   Beschreibung der Liste
  @param  liste   die auszugebene Liste
  @param  anzahl  Anzahl der Listenelemente
**/
//###############################################################################
void liste_ganzzahl_werte_ausgabe(char *titel, int *liste, int anzahl)
{
  printf("\n%-30s[", titel);
  liste_ganzzahl_vektor_ausgeben(liste, anzahl, ", ", 0);
  printf("]");
}

//###############################################################################
/** 
  Schreibt die mittels Zeiger übergebene Liste als Vektor in die Standard-Ausgabe
  
  @param  titel   Beschreibung der Liste
  @param  liste   Zeiger auf die Liste
  @param  anzahl  Länge der Liste
  @param  spalten Anzahl der Spalten in der Matrix
  @param  breite  Breite der Spalten in der Matrix
**/
//###############################################################################
void liste_gleitzahl_matrix_ausgeben(const char *titel, double *liste, int anzahl, int spalten, int breite)
{
  printf("\n%s\n", titel);
  for (int i = 0; i < anzahl; )
  {
    printf("\n");
    for (int j = 0; j < spalten && i < anzahl; j++)
    {
      printf("%*.2lf", breite, liste[i++]);
    }
  }
}

//###############################################################################
/** 
  Schreibt die mittels Zeiger übergebene Liste mit Titel in die Standard-Ausgabe
  
  @param  titel   Beschreibung der Liste
  @param  liste   die auszugebene Liste
  @param  anzahl  Anzahl der Listenelemente
**/
//###############################################################################
void liste_gleitzahl_werte_ausgabe(char *titel, double *liste, int anzahl)
{
  printf("\n%-30s[", titel);
  liste_gleitzahl_vektor_ausgeben(liste, anzahl, ", ", 0);
  printf("]");
}
