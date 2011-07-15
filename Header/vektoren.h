/*###############################################################################
  Funktions-Prototypen 
###############################################################################*/
int *liste_ganzzahl_erstellen(int anzahl);
double *liste_gleitzahl_erstellen(int anzahl);
char *liste_symbole_erstellen(int anzahl);

int *liste_ganzzahl_minimum(int *liste, int anzahl);
int *liste_ganzzahl_maximum(int *liste, int anzahl);
double *liste_gleitzahl_minimum(double *liste, int anzahl);
double *liste_gleitzahl_maximum(double *liste, int anzahl);

int *liste_ganzzahl_werte_schreiben(int *liste, int anzahl, int wert);
double *liste_gleitzahl_werte_schreiben(double *liste, int anzahl, double wert);

int *liste_ganzzahl_kopieren(int *liste, int anzahl);
double *liste_gleitzahl_kopieren(double *liste, int anzahl);
char *liste_symbole_kopieren(char *liste, int anzahl);

int ganzzahl_vergleichen(const void *a, const void *b);
int gleitzahl_vergleichen(const void *a, const void *b);
void liste_ganzzahl_sortieren(int *liste, int anzahl);
void liste_gleitzahl_sortieren(double *liste, int anzahl);

double liste_ganzzahl_varianz_berechnen(int *liste, int anzahl, double schnitt);
double liste_gleitzahl_varianz_berechnen(double *liste, int anzahl, double schnitt);

double liste_ganzzahl_median_berechnen(int *liste, int anzahl);
double liste_gleitzahl_median_berechnen(double *liste, int anzahl);

void liste_ganzzahl_vektor_ausgeben(int *liste, int anzahl, char *kleber, int breite);
void liste_ganzzahl_matrix_ausgeben(const char *titel, int *liste, int anzahl, int spalten, int breite);
void liste_gleitzahl_vektor_ausgeben(double *liste, int anzahl, char *kleber, int breite);
void liste_gleitzahl_matrix_ausgeben(const char *titel, double *liste, int anzahl, int spalten, int breite);

