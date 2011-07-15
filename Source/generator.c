//###############################################################################
/** 
  Initialisiert den Zufalls-Generator
**/
//###############################################################################
void zufall_initialisieren(void)
{
  srand((unsigned) time(NULL));
}

//###############################################################################
/** 
  Generiert zufällig eine Ganzzahl in einem anzugebenen Bereich
  
  @param  min Untere Grenze des Bereich
  @param  max Obere Grenze des Bereich
  
  @return Zufällig generierte Ganzzahl
**/
//###############################################################################
int ganzzahl_generieren(int min, int max)
{
  return min + ( rand() % (( min < max ? max - min : min - max ) + 1 ));
}

//###############################################################################
/** 
  Generiert zufällig eine Ganzzahl in einem anzugebenen Bereich
  
  @param  min Untere Grenze des Bereich
  @param  max Obere Grenze des Bereich
  
  @return Zufällig generierte Gleitzahl
**/
//###############################################################################
double gleitzahl_generieren(double min, double max)
{
  double rnd = rand() / (double) RAND_MAX;
  
  return (min < max) ? rnd * (max - min) + min : rnd * (min - max) + max;
}

//###############################################################################
/** 
  Schreibt zufällige Werte in die/den mittels Zeiger übergebene Ganzzahl-
  Liste/Bereich
  
  @param  liste   Zeiger auf die Liste
  @param  anzahl  Anzahl der Elemente in der Liste
  @param  min     Untere Grenze des Bereich
  @param  max     Obere Grenze des Bereich
  
  @return Zeiger auf die Liste
**/
//###############################################################################
int *liste_ganzzahl_zufall_schreiben(int *liste, int anzahl, int min, int max)
{
  for (int *p = liste; p < (liste + anzahl); p++) {
    *p = ganzzahl_generieren(min, max);
  }

  return liste;
}

//###############################################################################
/** 
  Sammelt zufällig Elementpositionen der gegebenen Liste bis alle einmal vorkamen
  
  @param  liste Zeiger auf die Liste
  @param  anzahl Anzahl der Elemente in der Liste
  
  @return Anzahl der Versuche
**/
//###############################################################################
int liste_ganzzahl_zufall_sammeln(int *liste, int anzahl)
{
  int summe = 0;
  int nummer = 0;

  for (int versuch = 0; versuch < anzahl; summe++) {
    nummer = ganzzahl_generieren(0, anzahl - 1);
    versuch += (*(liste + nummer) == 0) ? 1 : 0;
    *(liste + nummer) += 1;
  }

  return summe;
}

//###############################################################################
/** 
  Sammelt zufällig Elementpositionen der gegebenen Liste bis alle einmal vorkamen
  
  @param  liste Zeiger auf die Liste
  @param  anzahl Anzahl der Elemente in der Liste
  @param  limit ???
  
  @return Zeiger auf erstellte Liste
**/
//###############################################################################
int *liste_ganzzahl_zufall_anzahl(int *liste, int anzahl, int limit)
{
  int nummer = 0;
  
  int *result = liste_ganzzahl_erstellen(limit);

  for (int versuch = 0; versuch < limit; versuch++) {
    nummer = ganzzahl_generieren(0, anzahl - 1);
    *(liste + nummer) += 1;
  }

  return result;
}

//###############################################################################
/** 
  Sammelt zufällig Elementpositionen der gegebenen Liste bis alle einmal vorkamen
  
  @param  liste Zeiger auf die Liste
  @param  anzahl Anzahl der Elemente in der Liste
  @param  limit ???
  
  @return Zeiger auf erstellte Liste
**/
//###############################################################################
int *liste_ganzzahl_zufall_unikat(int *liste, int anzahl, int limit)
{
  int nummer = 0;

  int *result = liste_ganzzahl_erstellen(limit);

  for (int versuch = 0; versuch < limit; versuch++) {
    nummer = ganzzahl_generieren(0, anzahl - 1);
    *(liste + nummer) += 1;
  }

  return result;
}

//###############################################################################
/** 
  Schreibt zufällige Werte in die/den mittels Zeiger übergebene Ganzzahl-
  Liste/Bereich
  
  @param  liste   Zeiger auf die Liste
  @param  anzahl  Anzahl der Elemente in der Liste
  @param  min     Untere Grenze des Bereich
  @param  max     Obere Grenze des Bereich
  
  @return Zeiger auf die Liste
**/
//###############################################################################
double *liste_gleitzahl_zufall_schreiben(double *liste, int anzahl, int min, int max)
{
  for (double *p = liste; p < (liste + anzahl); p++) {
    *p = gleitzahl_generieren(min, max);
  }

  return liste;
}

//###############################################################################
/** 
  Sammelt zufällig Elementpositionen der gegebenen Liste bis alle einmal vorkamen
  
  @param  liste Zeiger auf die Liste
  @param  anzahl Anzahl der Elemente in der Liste
  
  @return Anzahl der Versuche
**/
//###############################################################################
int liste_gleitzahl_zufall_sammeln(double *liste, int anzahl)
{
  int summe = 0;
  int nummer = 0;

  for (int versuch = 0; versuch < anzahl; summe++) {
    nummer = ganzzahl_generieren(0, anzahl - 1);
    versuch += (*(liste + nummer) == 0) ? 1 : 0;
    *(liste + nummer) += 1;
  }

  return summe;
}
