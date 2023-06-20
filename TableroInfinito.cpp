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
struct TableroInfinitoHeader
{
  BBNode *tablero;
};
/* INV.REP.:
 * COMPLETAR
 */

typedef TableroInfinitoHeader *TableroInfinito;

//--------------------------------------------------------------------------
TableroInfinito TInfInicial()
{
  TableroInfinitoHeader *t = new TableroInfinitoHeader;
  t->tablero->kx = 0;
  t->tablero->ky = 0;
  return t;
}

bool esColorValido(Color color)
{
  return color == ROJO || color == VERDE || color == NEGRO || color == AZUL;
}

bool esDireccionValida(Dir dir)
{
  return dir == NORTE || dir == ESTE || dir == SUR || dir == OESTE;
}

//--------------------------------------------------------------------------
void PonerNTInf(TableroInfinito t, Color color, int n)
{
  if (!esColorValido(color))
  {
    BOOM("ERROR debes ingresar un color válido");
  }
  t->tablero->bolitas[color] = +n;
}

//--------------------------------------------------------------------------
void SacarNTInf(TableroInfinito t, Color color, int n)
{
  // PRECOND:
  //  * el color es válido
  //  * hay al menos n bolitas en la celda actual en t
  if (t->tablero->bolitas[color] < n)
  {
    BOOM("ERROR la cantidad que queres sacar es mayor a la cantidad que hay en la celda actual");
  }
  if (!esColorValido(color))
  {
    BOOM("ERROR debes ingresar un color válido");
  }
      t->tablero->bolitas[color] = -n;
}

//--------------------------------------------------------------------------
void MoverNTInf(TableroInfinito t, Dir dir, int n)
{
  // PRECOND: la dirección dada es válida
  if (!esDireccionValida(dir))
  {
    BOOM("ERROR debes ingresar una dirección válida");
  }
  BBNode *celdaActual = t->tablero;
  while (n > 0 && celdaActual->hijo[dir] != NULL)
  {
    celdaActual = celdaActual->hijo[dir];
    n--;
  }
}

//--------------------------------------------------------------------------
int nroBolitasTInf(TableroInfinito t, Color color)
{
  // PRECOND: el color es válido
  if (!esColorValido(color))
  {
    BOOM("ERROR debes ingresar un color válido");
  }
  return t->tablero->bolitas[color];
}

//--------------------------------------------------------------------------
void LiberarTInf(TableroInfinito t)
{
  // COMPLETAR
}

//==========================================================================
// Impresión para verificaciones
//==========================================================================
void PrintRepTInf(TableroInfinito t)
{

  // PISTA: utilizar PrintBB de BiBST
}
