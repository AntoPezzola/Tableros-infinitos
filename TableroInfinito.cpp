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
  BBNode *celda;
  int y; // coordenada y de la celda actual
  int x; // coordenada x de la celda actual
};
/* INV.REP.:
 * COMPLETAR
 */

typedef TableroInfinitoHeader *TableroInfinito;

//--------------------------------------------------------------------------
TableroInfinito TInfInicial()
{
  TableroInfinito t = new TableroInfinitoHeader;
  t->celda = EMPTYBB; 
  t->x = 0;
  t->y = 0;
  return t;
}

//--------------------------------------------------------------------------
void PonerNTInf(TableroInfinito t, Color color, int n)
{
  if (!VALIDCOLOR(color))
  {
    BOOM("ERROR debes ingresar un color válido");
  }
   t->celda = insertBBNode(t->celda, t->x, t->y); 
   t->celda->bolitas[color] += n; 
 // PrintBB(t->celda); 
}

//--------------------------------------------------------------------------
void SacarNTInf(TableroInfinito t, Color color, int n)
{
  // PRECOND:
  //  * el color es válido
  //  * hay al menos n bolitas en la celda actual en t
  if (t->celda->bolitas[color] < n)
  {
    BOOM("ERROR la cantidad que queres sacar es mayor a la cantidad que hay en la celda actual");
  }
  if (!VALIDCOLOR(color))
  {
    BOOM("ERROR debes ingresar un color válido");
  }
  t->celda = insertBBNode(t->celda, t->x, t->y); 
  t->celda->bolitas[color] -= n; 

}

//--------------------------------------------------------------------------
void MoverNTInf(TableroInfinito t, Dir dir, int n){
  // PRECOND: la dirección dada es válida
  if (!VALIDDIR(dir))
  {
    BOOM("ERROR debes ingresar una dirección válida");
  }

  if (n <= 0){
    return;
  }
  if (dir == NORTE){
    t->y += 1;
  }
  if (dir == ESTE){
    t->x += 1;
  }
  if (dir == OESTE){
    t->x -= 1;
  }
  if (dir == SUR){
    t->y -= 1;
  }
  MoverNTInf(t, dir, n-1); 
}

//--------------------------------------------------------------------------
int nroBolitasTInf(TableroInfinito t, Color color)
{
  // PRECOND: el color es válido
  if (!VALIDCOLOR(color))
  {
    BOOM("ERROR debes ingresar un color válido");
  }
  return t->celda->bolitas[color]; 
}

//--------------------------------------------------------------------------
void LiberarTInf(TableroInfinito t)
{
  if (t == NULL)
  {
    return;
  }

  LiberarBiBST(t->celda);

  delete t->celda;
  delete t;
}

//==========================================================================
// Impresión para verificaciones
//==========================================================================
void PrintRepTInf(TableroInfinito t)
{
  if (t == NULL)
  {
    return;
  cout << "Celda actual: " << "(" << t->x << " , " << t->y << ")" << endl; 
  }
  if (t->celda == EMPTYBB)
  {
    return;
  }
  PrintBB(t->celda);
}
