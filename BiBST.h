
#include <iostream>
#include "TiposBasicos.h"
using namespace std;

#ifndef BBNODEALREADYDEFINED
#define BBNODEALREADYDEFINED

struct BBNode {
  int kx;                                     // Primera clave
  int ky;                                     // Segunda clave 
  int bolitas[4]  = { 0, 0, 0, 0 };           // Las 4 cantidades de bolitas de la celda (array indexado por Color)
  BBNode* hijo[4] = {NULL, NULL, NULL, NULL}; // Los 4 hijos (array indexado por Cuadrante)
};
/* INV.REP.
   * Los pares de claves no se repiten en el arbol
   * Las claves de los hijos del BBNode no son iguales que el del raiz
*/
#endif

typedef BBNode* BiBST;
#define EMPTYBB NULL

BBNode* findBBNode  (BBNode* nodo, int x, int y);  
BBNode* insertBBNode(BBNode* nodo, int x, int y);

void    LiberarBiBST(BiBST t);

void PrintBB(BiBST t);
