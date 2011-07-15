//###############################################################################
/** 
  Liefert eine neue Matrix als Ergebnis aus der Addition zweier gegebener 
  quadratischer Matrizen

  @param  matrix1     Erste Matrix
  @param  matrix2     Zweite Matrix
  @param  dimension   Anzahl Zeilen/Spalten der Matrizen
  
  @return Zeiger auf erstellte Matrix
**/
//###############################################################################
int *matrix_ganzzahl_addieren(int *matrix1, int *matrix2, int dimension)
{
  int *matrix = liste_ganzzahl_erstellen(dimension * dimension);

  for (int i = 0; i < dimension * dimension; i++) {
    *(matrix + i) = *(matrix1 + i) + *(matrix2 + i);
  }
  
  return matrix;
}

//###############################################################################
/** 
  Liefert eine neue Matrix als Ergebnis aus der Subtraktion zweier gegebener 
  quadratischer Matrizen

  @param  matrix1     Erste Matrix
  @param  matrix2     Zweite Matrix
  @param  dimension   Anzahl Zeilen/Spalten der Matrizen
  
  @return Zeiger auf erstellte Matrix
**/
//###############################################################################
int *matrix_ganzzahl_subtrahieren(int *matrix1, int *matrix2, int dimension)
{
  int *matrix = liste_ganzzahl_erstellen(dimension * dimension);

  for (int i = 0; i < dimension * dimension; i++) {
    *(matrix + i) = *(matrix1 + i) - *(matrix2 + i);
  }
  
  return matrix;
}

//###############################################################################
/** 
  Liefert eine neue Matrix als Ergebnis aus der Multiplikation zweier gegebener 
  quadratischer Matrizen

  @param  matrix1     Erste Matrix
  @param  matrix2     Zweite Matrix
  @param  dimension   Anzahl Zeilen/Spalten der Matrizen
  
  @return Zeiger auf erstellte Matrix
**/
//###############################################################################
int *matrix_ganzzahl_multiplizieren(int *matrix1, int *matrix2, int dimension)
{
  int *matrix = liste_ganzzahl_erstellen(dimension * dimension);

  // i Zeilen, j Spalten, m Durchlauf
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      for (int m = 0; m < dimension; m++) {
        *(matrix + (i * dimension) + j) += *(matrix1 + (i * dimension) + m) * *(matrix2 + (m * dimension) + j);
      }
    }
  }
  
  return matrix;
}
