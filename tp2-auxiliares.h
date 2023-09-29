
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool esAdyacenteValida (tablero& t, pos p, int i, int j);
bool hayBomba (tablero& t, pos p, int i, int j);
bool esBanderita (pos p, banderitas& b);
void sacarBanderita (pos p, banderitas& b);
void plantarBanderita (pos p, banderitas& b);
int indice (pos p, banderitas& b);
int cantidadDeEspaciosSinBomba (tablero& t);
void descubrirMultiplesPosiciones(tablero& t, banderitas& b, pos p, jugadas& j);
bool esPermutacionJugadas(jugadas& j1, jugadas& j2);
bool esPosicionSinJugarYSinBanderita (pos &p, jugadas &j, banderitas &b, tablero &t);
bool hayPosicionSugerible (jugadas &j,banderitas &b,tablero &t, pos& p);
bool esAdyacenteA121(pos p, jugadas &j);