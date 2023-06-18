#include <iostream>
using namespace std;
#include <iomanip>
#include "TiposBasicos.h"
#include "TableroInfinito.h"

int main(){
  TableroInfinito t = TInfInicial();
  PonerNTInf(t, ROJO,  1);  PrintRepTInf(t);
  PonerNTInf(t, AZUL,  1);
  MoverNTInf(t, OESTE, 1);
  PonerNTInf(t, VERDE, 1);  PrintRepTInf(t);
  MoverNTInf(t, OESTE, 4);
  PonerNTInf(t, ROJO,  1);
  PonerNTInf(t, AZUL,  2);  PrintRepTInf(t);
  MoverNTInf(t, ESTE,  5);
  PonerNTInf(t, ROJO,  2);  PrintRepTInf(t);
  int r = nroBolitasTInf(t, ROJO);
  int b = nroBolitasTInf(t, AZUL);
  MoverNTInf(t, ESTE,  1);
  MoverNTInf(t, NORTE, 1);
  PonerNTInf(t, NEGRO, 1);  PrintRepTInf(t);
  MoverNTInf(t, SUR,   1);
  MoverNTInf(t, OESTE, 6);
  int b2 = nroBolitasTInf(t, AZUL); 
  
  cout << "Test nroBolitas(Rojo) ( 0,0) - "; PRINTCOLORN(ROJO, r);  cout << " (debe ser `Rojo: 3`)" << endl;
  cout << "Test nroBolitas(Azul) ( 0,0) - "; PRINTCOLORN(AZUL, b);  cout << " (debe ser `Azul: 1`)" << endl;
  cout << "Test nroBolitas(Azul) (-5,0) - "; PRINTCOLORN(AZUL, b2); cout << " (debe ser `Azul: 2`)" << endl;

  LiberarTInf(t);
}

/* La salida de este programa debe ser la siguiente:

Celda actual: (0, 0)
BiBST:
  (0,0): Azul: 0, Negro: 0, Rojo: 1, Verde: 0

Celda actual: (-1, 0)
BiBST:
  (0,0): Azul: 1, Negro: 0, Rojo: 1, Verde: 0
   (-1,0): Azul: 0, Negro: 0, Rojo: 0, Verde: 1

Celda actual: (-5, 0)
BiBST:
  (0,0): Azul: 1, Negro: 0, Rojo: 1, Verde: 0
   (-1,0): Azul: 0, Negro: 0, Rojo: 0, Verde: 1
    (-5,0): Azul: 2, Negro: 0, Rojo: 1, Verde: 0

Celda actual: (0, 0)
BiBST:
  (0,0): Azul: 1, Negro: 0, Rojo: 3, Verde: 0
   (-1,0): Azul: 0, Negro: 0, Rojo: 0, Verde: 1
    (-5,0): Azul: 2, Negro: 0, Rojo: 1, Verde: 0

Celda actual: (1, 1)
BiBST:
  (0,0): Azul: 1, Negro: 0, Rojo: 3, Verde: 0
   (1,1): Azul: 0, Negro: 1, Rojo: 0, Verde: 0
   (-1,0): Azul: 0, Negro: 0, Rojo: 0, Verde: 1
    (-5,0): Azul: 2, Negro: 0, Rojo: 1, Verde: 0

Test nroBolitas(Rojo) ( 0,0) - Rojo: 3 (debe ser `Rojo: 3`)
Test nroBolitas(Azul) ( 0,0) - Azul: 1 (debe ser `Azul: 1`)
Test nroBolitas(Azul) (-5,0) - Azul: 2 (debe ser `Azul: 2`)
*/
     