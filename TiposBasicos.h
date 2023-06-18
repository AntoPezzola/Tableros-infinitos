
#include <iostream>
using namespace std;

#define INDENT(tab) { for(int it=0; it<tab; it++) { cout << " "; } }
#define BOOM(msg) cerr << msg << std::endl; exit(1)

// Colores
typedef int Color;
#define AZUL  0
#define NEGRO 1
#define ROJO  2
#define VERDE 3
#define PRINTCOLOR(color) switch (color) { case AZUL: cout << "Azul"; break; case NEGRO: cout << "Negro"; break; case ROJO: cout << "Rojo"; break; case VERDE: cout << "Verde"; break; default: cerr << "ERROR: " << color << " no es una representación de un color válido"; exit(1); }
#define PRINTCOLORN(color, n) PRINTCOLOR(color); cout << ": " << n
#define VALIDCOLOR(color) (AZUL <= color && color <= VERDE)

// Direcciones
typedef int Dir;
#define NORTE 0
#define ESTE  1
#define SUR   2
#define OESTE 3
#define PRINTDIR(dir) switch (dir) { case NORTE: cout << "Norte"; break; case ESTE: cout << "Este"; break; case SUR: cout << "Sur"; break; case Oeste: cout << "Oeste"; break; default: cerr << "ERROR: " << dir << " no es una representación de una dirección válida"; exit(1); }
#define PRINTDIRN(dir, n) PRINTDIR(dir); cout << ": " << n
#define VALIDDIR(dir) (NORTE <= dir && dir <= OESTE)

// Cuadrantes
typedef int Cuadrante;
#define NE 0
#define SE 1
#define NO 2
#define SO 3
