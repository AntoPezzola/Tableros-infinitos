#include <iostream>
#include <algorithm>
#include "BiBST.h"
using namespace std;

//==========================================================================
// Invariante de representación
//==========================================================================
/* INV.REP.
 * COMPLETAR
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

  if (nodo->kx < x && nodo->ky < y)
  {
    return findBBNode(nodo->hijo[NE], x, y);
  }
  if (nodo->kx < x && nodo->ky >= y) 
  {
    return findBBNode(nodo->hijo[SE], x, y);
  }
  if (nodo->kx >= x && nodo->ky < y)
  {
    return findBBNode(nodo->hijo[NO], x, y);
  }
  if (nodo->kx >= x &&nodo->ky >= y)

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

  if (nodo->kx == x && nodo->ky == y)
  {
    return nodo;
  }

  if (nodo->kx < x && nodo->ky < y)
  {
    nodo->hijo[NE] = insertBBNode(nodo->hijo[NE], x, y);
  }
  if (nodo->kx < x &&nodo->ky >= y)
  {
    nodo->hijo[SE] = insertBBNode(nodo->hijo[SE], x, y);
  }
  if (nodo->kx >= x && nodo->ky < y)
  {
    nodo->hijo[NO] = insertBBNode(nodo->hijo[NO], x, y);
  }
  if (nodo->kx >= x && nodo->ky >=  y)
  {
    nodo->hijo[SO] = insertBBNode(nodo->hijo[SO], x, y);
  }

  return nodo;
}

void LiberarBiBST(BiBST t){
  
  

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