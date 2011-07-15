/*###############################################################################
  Funktions-Prototypen 
###############################################################################*/
void zufall_initialisieren(void);

int ganzzahl_generieren(int min, int max);
double gleitzahl_generieren(double min, double max);

int *liste_ganzzahl_zufall_schreiben(int *liste, int anzahl, int min, int max);
double *liste_gleitzahl_zufall_schreiben(double *liste, int anzahl, int min, int max);

int liste_ganzzahl_zufall_sammeln(int *liste, int anzahl);
int liste_gleitzahl_zufall_sammeln(double *liste, int anzahl);