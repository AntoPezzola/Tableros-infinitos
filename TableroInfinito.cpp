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
  BBNode *celda; // celda actual, la cual se incializa con 0,0 sin bolitas, ni nodos
  int x; // coordenada x de la celda actual
  int y; // coordenada y de la celda actual
};
/* INV.REP.:
   * Cuando saco bolitas o pongo bolitas en celda actual, la misma debe exisir en el tablero
   * Para pedirle la cantidad de bolitas en la celda actual, la misma debe existir en el tablero
   * No existen celdas repetidas en el tablero
 */

typedef TableroInfinitoHeader *TableroInfinito;

//--------------------------------------------------------------------------
TableroInfinito TInfInicial()
{
  TableroInfinito t = new TableroInfinitoHeader;
  t->celda = insertBBNode(EMPTYBB, 0, 0);
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
  BBNode *celdaNueva = findBBNode(t->celda, t->x, t->y);
  celdaNueva->bolitas[color] += n;
}

//--------------------------------------------------------------------------
void SacarNTInf(TableroInfinito t, Color color, int n)
{
  // PRECOND:
  //  * el color es válido
  //  * hay al menos n bolitas en la celda actual en t
  BBNode *celdaActual = findBBNode(t->celda, t->x, t->y);
  if (celdaActual == EMPTYBB)
  {
    BOOM("ERROR la celda no existe");
  }

  if (celdaActual->bolitas[color] < n)
  {
    BOOM("ERROR la cantidad dada es mayor a la cantidad que hay en la celda actual");
  }
  if (!VALIDCOLOR(color))
  {
    BOOM("ERROR debes ingresar un color valido");
  }
  celdaActual->bolitas[color] -= n;
}

//--------------------------------------------------------------------------
void MoverNTInf(TableroInfinito t, Dir dir, int n)
{
  // PRECOND: la dirección dada es válida
  if (!VALIDDIR(dir))
  {
    BOOM("ERROR debes ingresar una dirección valida");
  }

  if (n <= 0)
  {
    return;
  }

  if (dir == NORTE)
  {
    t->y += 1;
  }
  if (dir == ESTE)
  {
    t->x += 1;
  }
  if (dir == OESTE)
  {
    t->x -= 1;
  }
  if (dir == SUR)
  {
    t->y -= 1;
  }
  MoverNTInf(t, dir, n - 1);
  BBNode *celdaNueva = insertBBNode(t->celda, t->x, t->y);
}

//--------------------------------------------------------------------------
int nroBolitasTInf(TableroInfinito t, Color color)
{
  // PRECOND: el color es válido
  if (!VALIDCOLOR(color))
  {
    BOOM("ERROR debes ingresar un color válido");
  }
  BBNode *celdaActual = findBBNode(t->celda, t->x, t->y);

  if (celdaActual == EMPTYBB)
  {
    BOOM("ERROR la celda no existe");
  }
  return celdaActual->bolitas[color];
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
  }
  if (t->celda == EMPTYBB)
  {
    return;
  }
  cout << "Celda actual: "
       << "(" << t->x << "," << t->y << ")" << endl;
  PrintBB(t->celda);
  cout << endl;
}
