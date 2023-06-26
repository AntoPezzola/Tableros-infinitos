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
BBNode *findBBNode(BBNode *nodo, int x, int y)
{
  if (nodo == NULL)
  {
    return NULL;
  }

  if (nodo->kx == x && nodo->ky == y)
  {
    return nodo;
  }

  if (x > nodo->kx && y > nodo->ky)
  {
    return findBBNode(nodo->hijo[NE], x, y);
  }
  if (x > nodo->kx && y <= nodo->ky)
  {
    return findBBNode(nodo->hijo[SE], x, y);
  }
  if (x <= nodo->kx && y > nodo->ky)
  {
    return findBBNode(nodo->hijo[NO], x, y);
  }
  if (x <= nodo->kx && y <= nodo->ky)

  {
    return findBBNode(nodo->hijo[SO], x, y);
  }

  return NULL;
}

BBNode *insertBBNode(BBNode *nodo, int x, int y)
{
  if (nodo == NULL)
  {
    BBNode *nuevoNodo = new BBNode;
    nuevoNodo->kx = x;
    nuevoNodo->ky = y;
    return nuevoNodo;
  }

   BBNode* nodoEncontrado = findBBNode(nodo, x, y) ; 
   if ( nodoEncontrado != NULL) {
    return nodoEncontrado; 
   }

  if (x > nodo->kx && y > nodo->ky)
  {
    nodo->hijo[NE] = insertBBNode(nodo->hijo[NE], x, y);
    return nodo->hijo[NE];
  }
  if (x > nodo->kx && y <= nodo->ky)
  {
    nodo->hijo[SE] = insertBBNode(nodo->hijo[SE], x, y);
    return nodo->hijo[SE];
  }
  if (x <= nodo->kx && y > nodo->ky)
  {
    nodo->hijo[NO] = insertBBNode(nodo->hijo[NO], x, y);
    return nodo->hijo[NO];
  }
  if (x <= nodo->kx && y <= nodo->ky)
  {
    nodo->hijo[SO] = insertBBNode(nodo->hijo[SO], x, y);
    return nodo->hijo[SO];
  }
  return nodo;
}

void LiberarBiBST(BiBST t)
{
  if (t != NULL)
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