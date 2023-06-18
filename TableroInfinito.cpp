#include <iostream>
#include <iomanip>
#include <algorithm>
#include "TiposBasicos.h"
#include "TableroInfinito.h"
#include "BiBST.h"
using namespace std;

//==========================================================================
// Implementación de TableroInfinito
//==========================================================================
struct TableroInfinitoHeader {
  // COMPLETAR
}; 
/* INV.REP.:
  * COMPLETAR
*/

//--------------------------------------------------------------------------
TableroInfinito TInfInicial(){
  return NULL; // REEMPLAZAR
}

//--------------------------------------------------------------------------
void PonerNTInf(TableroInfinito t, Color color, int n){
  // PRECOND: el color es válido
  
  // COMPLETAR
}

//--------------------------------------------------------------------------
void SacarNTInf(TableroInfinito t, Color color, int n){
  // PRECOND:
  //  * el color es válido
  //  * hay al menos n bolitas en la celda actual en t
  
  // COMPLETAR
}

//--------------------------------------------------------------------------
void MoverNTInf(TableroInfinito t, Dir dir, int n){
  // PRECOND: la dirección dada es válida
  
  // COMPLETAR
}

//--------------------------------------------------------------------------
int nroBolitasTInf(TableroInfinito t, Color color) {
  // PRECOND: el color es válido
  
  return 0; // REEMPLAZAR
}

//--------------------------------------------------------------------------
void LiberarTInf(TableroInfinito t){
  // COMPLETAR
}

//==========================================================================
// Impresión para verificaciones
//==========================================================================
void PrintRepTInf(TableroInfinito t) {
  // COMPLETAR 
  // PISTA: utilizar PrintBB de BiBST
}
