#include <iostream>
#include <algorithm>
#include "BiBST.h"
using namespace std;

//==========================================================================
// Invariante de representación
//==========================================================================
/* INV.REP.
 * Los pares de claves no se repiten en el arbol
 * Las claves de los hijos del BBNode no son iguales que el del raiz
 * La cantidad de bolitas en celda no puede ser negativa
 * El par de claves, deben ser numeros enteros
 */

//==========================================================================
// Implementación
//==========================================================================

bool esCuadranteNe(BBNode *nodo, int x, int y)
{
  return x > nodo->kx && y > nodo->ky;
}

bool esCuadranteSo(BBNode *nodo, int x, int y)
{
  return x <= nodo->kx && y <= nodo->ky;
}

bool esCuadranteNo(BBNode *nodo, int x, int y)
{
  return x <= nodo->kx && y > nodo->ky;
}
bool esCuadranteSe(BBNode *nodo, int x, int y)
{
  return x > nodo->kx && y <= nodo->ky;
}

bool esNodoNulo(BBNode *nodo)
{
  return nodo == EMPTYBB;
}

BBNode *findBBNode(BBNode *nodo, int x, int y)
{
  if (esNodoNulo(nodo))
  {
    return EMPTYBB;
  }

  if (nodo->kx == x && nodo->ky == y)
  {
    return nodo;
  }

  if (esCuadranteNe(nodo, x, y))
  {
    return findBBNode(nodo->hijo[NE], x, y);
  }
  if (esCuadranteSe(nodo, x, y))
  {
    return findBBNode(nodo->hijo[SE], x, y);
  }
  if (esCuadranteNo(nodo, x, y))
  {
    return findBBNode(nodo->hijo[NO], x, y);
  }
  if (esCuadranteSo(nodo, x, y))
  {
    return findBBNode(nodo->hijo[SO], x, y);
  }
  return EMPTYBB;
}

BBNode *insertBBNode(BBNode *nodo, int x, int y)
{

  BBNode *nodoActual;

  if (esNodoNulo(nodo))
  {
    BBNode *nuevoNodo = new BBNode;
    nuevoNodo->kx = x;
    nuevoNodo->ky = y;
    return nuevoNodo;
  }

  if (nodo->kx == x && nodo->ky == y)
  {
    return nodo;
  }

  if (esCuadranteNe(nodo, x, y))
  {
    nodoActual = insertBBNode(nodo->hijo[NE], x, y);
    if (esNodoNulo(nodo->hijo[NE]))
    {
      nodo->hijo[NE] = nodoActual;
    }
    return nodoActual;
  }
  if (esCuadranteSe(nodo, x, y))
  {
    nodoActual = insertBBNode(nodo->hijo[SE], x, y);
    if (esNodoNulo(nodo->hijo[SE]))
    {
      nodo->hijo[SE] = nodoActual;
    }
    return nodoActual;
  }
  if (esCuadranteNo(nodo, x, y))
  {
    nodoActual = insertBBNode(nodo->hijo[NO], x, y);
    if (esNodoNulo(nodo->hijo[NO]))
    {
      nodo->hijo[NO] = nodoActual;
    }
    return nodoActual;
  }
  if (esCuadranteSo(nodo, x, y))
  {
    nodoActual = insertBBNode(nodo->hijo[SO], x, y);
    if (esNodoNulo(nodo->hijo[SO]))
    {
      nodo->hijo[SO] = nodoActual;
    }
    return nodoActual;
  }
  delete nodoActual;
  return nodo;
}

void LiberarBiBST(BiBST t)
{
  if (t != EMPTYBB)
  {
    LiberarBiBST(t->hijo[NE]);
    LiberarBiBST(t->hijo[SE]);
    LiberarBiBST(t->hijo[NO]);
    LiberarBiBST(t->hijo[SO]);

    delete t;
  }
}

//==========================================================================
// Impresión para verificaciones
//==========================================================================
void PrintBBNode(BBNode *t, int tab)
{
  if (t == NULL)
  {
    return;
  }
  INDENT(tab)
  cout << "  (" << t->kx << "," << t->ky << "): ";
  PRINTCOLORN(AZUL, t->bolitas[AZUL]);
  cout << ", ";
  PRINTCOLORN(NEGRO, t->bolitas[NEGRO]);
  cout << ", ";
  PRINTCOLORN(ROJO, t->bolitas[ROJO]);
  cout << ", ";
  PRINTCOLORN(VERDE, t->bolitas[VERDE]);
  cout << endl;
  PrintBBNode(t->hijo[NE], ++tab);
  PrintBBNode(t->hijo[SE], tab);
  PrintBBNode(t->hijo[NO], tab);
  PrintBBNode(t->hijo[SO], tab);
}

void PrintBB(BiBST t)
{
  cout << "BiBST:" << endl;
  PrintBBNode(t, 0);
}