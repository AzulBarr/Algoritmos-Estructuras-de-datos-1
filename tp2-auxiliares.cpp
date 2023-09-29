//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

bool esCoordenadaValida (int coordenada, int largoTablero){
    if (0 <= coordenada && coordenada < largoTablero){
        return true;
    } else {
        return false;
    }
}
bool esPosicionValida (int x, int y, int largoTablero){
    return esCoordenadaValida (x, largoTablero)
           && esCoordenadaValida (y,largoTablero);
}
bool esAdyacenteValida (tablero &t, pos p,int i, int j){
    return esPosicionValida(p.first + i, p.second + j, t.size()) && (i!= 0 || j!=0);
}

bool hayBomba (tablero &t, pos p, int i, int j){
    if (t[p.first + i][p.second + j]){
        return true;
    } else {
        return false;
    }
}

/******++++**************************** EJERCICIO cambiarBanderita ***********+++***********************/

bool esBanderita (pos p, banderitas& b){
    int i = 0;
    while (i < b.size() && (b[i] != p)){
        i++;
    }
    return i < b.size();
}

int indice (pos p, banderitas &b){
    int i = 0;
    while (i < b.size() && (b[i] != p)){
        i++;
    }
    return i;
}

void swap(pos& a, pos& b){
    pos c = a;
    a = b ;
    b = c;
}

void sacarBanderita (pos p, banderitas& b){
    int i = indice(p, b);
    swap (b[i], b[b.size()-1]);
    b.pop_back();
}

void plantarBanderita (pos p, banderitas& b){
    b.push_back(p);
}

int cantidadDeEspaciosSinBomba (tablero& t){
    int contador = 0;
    for (int i = 0; i < t.size(); i++){
        for (int k = 0; k < t.size(); k++){
            if (!t[i][k]){
                contador += 1;
            }
        }
    }
    return contador;
}

bool esJugada(jugada j, jugadas& js){
    int i = 0;
    while (i < js.size() && (js[i] != j)){
        i++;
    }
    return i < js.size();
}

bool esPosicionSinJugarYSinBanderita (pos &p, jugadas &j, banderitas &b, tablero &t){
    return esPosicionValida (p.first, p.second, t.size()) && !esJugada (jugada(p, minasAdyacentes(t,p)), j) && !esBanderita(p, b);
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/

void descubrirMultiplesPosiciones(tablero& t, banderitas& b, pos p, jugadas& j){
    for (int i = -1; i <= 1; i++) {
        for (int k = -1; k <= 1; k++) {

            int x = p.first + i;
            int y = p.second + k;
            pos pAdy(x,y);
            int cantMinasAdyPAdy = minasAdyacentes(t, pAdy);
            jugada jugNueva(pAdy, cantMinasAdyPAdy);

            if (esPosicionSinJugarYSinBanderita(pAdy, j, b, t)) {

                j.push_back(jugNueva);
                if (cantMinasAdyPAdy == 0) {
                    descubrirMultiplesPosiciones(t, b, pAdy, j);
                }
            }
        }
    }
}

//La función esPermutacionJugadas se usa para los casos de testing.
bool esPermutacionJugadas(jugadas& j1, jugadas& j2){
    bool res = true;
    if (j1.size() == j2.size()){
        for (int i = 0; i < j1.size(); ++i) {
            if (!esJugada(j1[i], j2)){
                res = false;
            }
        }
        return res;
    }
    else
        return false;
}

/******++++**************************** EJERCICIO sugerir121 ***********+++***********************/

bool es121Horizontal (pos p, jugadas &j){
    pos p3(p.first, p.second - 1);
    pos p4(p.first, p.second + 1);
    return esJugada(jugada(p3, 1), j) && esJugada(jugada(p, 2), j) &&
    esJugada(jugada(p4, 1), j);
}

bool es121Vertical (pos p, jugadas &j){
    pos p1(p.first - 1, p.second);
    pos p2(p.first + 1, p.second);
    return esJugada(jugada(p1, 1), j) && esJugada(jugada(p, 2), j) &&
           esJugada(jugada(p2, 1), j);
}

bool esAdyacenteA121(pos p, jugadas &j){
    pos p1(p.first - 1, p.second);
    pos p2(p.first + 1, p.second);
    pos p3(p.first, p.second - 1);
    pos p4(p.first, p.second + 1);
    return es121Horizontal(p1, j) || es121Horizontal(p2, j) ||
            es121Vertical(p3, j) || es121Vertical(p4, j);
}

bool hayPosicionSugerible (jugadas &j,banderitas &b,tablero &t, pos& p){
    bool existePos = false;
    if (!perdio(t,j) && !gano(t,j)) {
        for (int i = 0; i < t.size() && !existePos; i++) {
            for (int k = 0; k < t.size() && !existePos; k++) {
                p = pos(i, k);
                if (esPosicionSinJugarYSinBanderita(p, j, b, t) && esAdyacenteA121(p, j)){
                    existePos = true;
                }
            }
        }

    }
    return existePos;
}

