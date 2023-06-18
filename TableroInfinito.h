
#include <iostream>
#include "TiposBasicos.h"
using namespace std;

struct  TableroInfinitoHeader;
typedef TableroInfinitoHeader* TableroInfinito; // INV.REP.: el puntero no puede ser NULL.

TableroInfinito TInfInicial();
void PonerNTInf(TableroInfinito t, Color color, int n); /* PRECOND: el color es válido */
void SacarNTInf(TableroInfinito t, Color color, int n); /* PRECOND:
                                                            * el color es válido
                                                            * hay al menos n bolitas en la celda actual en ib
                                                        */
void MoverNTInf(TableroInfinito t, Dir   dir,   int n); /* PRECOND: la dir es válida */
int  nroBolitasTInf(TableroInfinito t, Color color);    /* PRECOND: el color es válido */

void LiberarTInf(TableroInfinito t);

void PrintRepTInf(TableroInfinito t);