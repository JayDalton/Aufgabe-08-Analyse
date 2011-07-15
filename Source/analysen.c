//###############################################################################
/** 
  Berechnet die aktuelle Zeitspanne seit dem übergebenem Zeitstempel

  @param  start Zeitstempel zur Berechnung der Dauer
  
  @return Anzahl Sekunden seit übergebenem Zeitstempel
**/
//###############################################################################
double dauer_berechnen(clock_t start)
{
  return (clock() - start) / (1.0 * CLOCKS_PER_SEC);
}

//###############################################################################
/** 
**/
//###############################################################################
double berechne_erwartungswert(int anzahl)
{
  double summe = 0;
  for (int i = 0; i < anzahl; i++) {
    summe += 1.0 / (i + 1);
  }
  return anzahl * summe;
}

//###############################################################################
/** 
  Wertet die mittels Zeiger übergebene Ganzzahl-Liste in der Standard-Ausgabe aus.
  Dabei werden die Werte für Minimum, Maximum, Summe, Median, Durchschnitt, Varianz,
  sowie Werte und Positionen des minimalen und maximalen Abstandes berechnet.
  
  @param  liste   Zeiger auf die Liste
  @param  anzahl  Länge der Liste
**/
//###############################################################################
void liste_ganzzahl_analysieren(int *liste, int anzahl)
{
  int *minimum = liste;
  int *maximum = liste;
  double summe = 0;
  double median = 0;
  double schnitt = 0;
  double varianz = 0;
  int index_min = 0;
  int index_max = 0;
  int abstand_min = abs(liste[0] - liste[1]);
  int abstand_max = abs(liste[0] - liste[1]);

  for (int i = 0; i < anzahl; i++)
  {
    if (liste[i] < *minimum) {
      minimum = &liste[i];
    }

    if (liste[i] > *maximum) {
      maximum = &liste[i];
    }
    
    summe += liste[i];
    
    if (i != 0 && abstand_min > abs(liste[i - 1] - liste[i]))
    {
      index_min = i - 1;
      abstand_min = abs(liste[i - 1] - liste[i]);
    }

    if (i != 0 && abstand_max < abs(liste[i - 1] - liste[i]))
    {
      index_max = i - 1;
      abstand_max = abs(liste[i - 1] - liste[i]);
    }
  }
  
  schnitt = summe / anzahl;
  median = liste_ganzzahl_median_berechnen(liste, anzahl);
  varianz = liste_ganzzahl_varianz_berechnen(liste, anzahl, schnitt);
  
  printf("\n");
  printf("\n%-20s%20d", "Laenge", anzahl);
  printf("\n%-20s%20d", "Minimum", *minimum);
  printf("\n%-20s%20d", "Maximum", *maximum);
  printf("\n%-20s%20.0lf", "Summe", summe);
  printf("\n%-20s%20lf", "Durchschnitt", schnitt);
  printf("\n%-20s%20lf", "Median", median);
  printf("\n%-20s%20lf", "Varianz", varianz);
  printf("\n%-20s%20lf", "Standardabweichung", sqrt(varianz));
  printf("\n%-20s%20d%15s%4d", "kleinster Abstand", abstand_min, "an Stelle", index_min);
  printf("\n%-20s%20d%15s%4d", "groesster Abstand", abstand_max, "an Stelle", index_max);
  printf("\n");
}

//###############################################################################
/** 
  Wertet die mittels Zeiger übergebene Ganzzahl-Liste in der Standard-Ausgabe aus.
  Dabei werden die Werte für Minimum, Maximum, Summe, Median, Durchschnitt, Varianz,
  sowie Werte und Positionen des minimalen und maximalen Abstandes berechnet.
  
  @param  liste   Zeiger auf die Liste
  @param  anzahl  Länge der Liste
**/
//###############################################################################
void liste_gleitzahl_analysieren(double *liste, int anzahl)
{
  double *minimum = liste;
  double *maximum = liste;
  double summe = 0;
  double median = 0;
  double schnitt = 0;
  double varianz = 0;
  int index_min = 0;
  int index_max = 0;
  double abstand_min = fabs(liste[0] - liste[1]);
  double abstand_max = fabs(liste[0] - liste[1]);

  for (int i = 0; i < anzahl; i++)
  {
    if (liste[i] < *minimum) {
      minimum = &liste[i];
    }

    if (liste[i] > *maximum) {
      maximum = &liste[i];
    }
    
    summe += liste[i];
    
    if (i != 0 && abstand_min > fabs(liste[i - 1] - liste[i]))
    {
      index_min = i - 1;
      abstand_min = fabs(liste[i - 1] - liste[i]);
    }

    if (i != 0 && abstand_max < fabs(liste[i - 1] - liste[i]))
    {
      index_max = i - 1;
      abstand_max = fabs(liste[i - 1] - liste[i]);
    }
  }
  
  schnitt = summe / anzahl;
  median = liste_gleitzahl_median_berechnen(liste, anzahl);
  varianz = liste_gleitzahl_varianz_berechnen(liste, anzahl, schnitt);
  
  printf("\n");
  printf("\n%-20s%20d", "Laenge", anzahl);
  printf("\n%-20s%20.2lf", "Minimum", *minimum);
  printf("\n%-20s%20.2lf", "Maximum", *maximum);
  printf("\n%-20s%20.2lf", "Summe", summe);
  printf("\n%-20s%20lf", "Durchschnitt", schnitt);
  printf("\n%-20s%20lf", "Median", median);
  printf("\n%-20s%20lf", "Varianz", varianz);
  printf("\n%-20s%20lf", "Standardabweichung", sqrt(varianz));
  printf("\n%-20s%20.2lf%15s%4d", "kleinster Abstand", abstand_min, "an Stelle", index_min);
  printf("\n%-20s%20.2lf%15s%4d", "groesster Abstand", abstand_max, "an Stelle", index_max);
  printf("\n");
}


