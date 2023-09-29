//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/*Para los cálculos de complejidad vamos a usar:
* b = longitud de banderitas
* j = longitud de jugadas
* t = cantidad de filas de tablero
* Repetidas veces vamos a usar que O(j) <= O(t^2) porque en el peor caso, la longitud de jugadas es igual a t^2
* lo mismo ocurre con O(b) <= O(t^2) */

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/
/* El tablero no se recorre en su totalidad, solo se fija si en la posición hay bomba o no y chequea las 8 posiciones
 * adyacentes. Como hayBomba se ejecuta una sola vez por iteración (y dentro de esta se hacen dos operaciones) y
 * adyacente válida 8 veces (y dentro de esta se hacen trece operaciones), la mayor cantidad de operaciones es
 * O(120) = O(1). */

int minasAdyacentes(tablero& t, pos p) {
    int i = -1;
    int contador = 0;
    while (i <= 1){
        int j = -1;
        while (j <= 1){
            if (esAdyacenteValida (t, p, i, j) && hayBomba (t, p, i, j)) {
                contador += 1;
            }
            j++;
        }
        i++;
    }
    return contador;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/
/* Esta función se fija si la posición p esta en banderitas con una busqueda lineal, en el peor caso de complejidad O(b).
 * Luego si está en banderitas, busca qué índice tiene esa posición en banderitas con otra busqueda lineal de
 * complejidad O(b).
 * Si no esta en banderitas la mete a la lista, complejidad O(1).
 * Por lo tanto, es O(b) + O(b) + O(1) = O(b) */

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    if (esBanderita (p, b)){
        sacarBanderita (p, b);
    } else {
        plantarBanderita (p, b);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
/* La función hace una busqueda lineal hasta que encuentra una bomba o termina la secuencia. En el peor de los casos
 * recorre toda la secuencia.
 * Tiene complejidad O(j).
 * Si queremos unificar esto con otros ejercicios lo podemos escrbir como O(t^2) ya que jugadas tiene como máximo
 * t^2 elementos. */

bool perdio(tablero& t, jugadas& j) {
    int i = 0;
    while (i<j.size() && !hayBomba(t, (j[i]).first, 0, 0)) {
        i++;
    }
    return i < j.size();
}

/******++++**************************** EJERCICIO gano ***********+++***********************/

/* Esta función primero se fija que no perdio, complejidad O(j) = O(t^2), y
 * luego se fija cual es la cantidad de espacios sin bomba que tiene el tablero haciendo una sumatoria
 * que recorre el tablero, por lo tanto, es de complejidad O(t^2).
 * Por ende, como entre las funciones hay un &&, se suman las complejidades: O(t^2) + O(t^2) = O(t^2). */

bool gano(tablero& t, jugadas& j) {
    return !perdio(t,j) && (cantidadDeEspaciosSinBomba(t) == j.size());
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
/* No tenemos en cuenta que es recursiva para analizar la complejidad.
 * Analicemos primero descubrirMultiplesPosiciones porque las demas funciones de las cuales depende jugarPlus son O(1).
 * NohayBomba es O(1) ya que solo chequea que no haya bomba en una posición.
 * Luego cantMinasAdyP como máximo realiza 8 iteraciones por lo tanto es O(1).
 *
 * DescubrirMultiplesPosiciones depende de esPosicionSinJugarYSinBanderita que tiene una complejidad de 0(j) + O(b)
 * ya que recorre jugadas y banderitas, ambas en el peor caso son O(t^2), luego O(t^2) + O(t^2) = O(t^2)
 * Ademas de esto, descubrirMultiplesPosiciones se fija la cantidad de minas adyacentes que como ya dijimos es O(1).
 * Concluyendo, jugarPlus es de complejidad O(t^2) sin tener en cuenta la recursividad. */

void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    int cantMinasAdyP = minasAdyacentes(t,p);
    j.push_back(jugada(p, cantMinasAdyP));
    if (!hayBomba(t,p,0,0) && cantMinasAdyP == 0){
        descubrirMultiplesPosiciones(t, b, p, j);
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
/* SugerirAutomatico121 depende de HayPosicionSugerible.

 * Veamos la complejidad de HayPosicionSugerible:
 * Lo que hace es fijarse si perdio (O(t^2)). Luego, chequea que no haya ganado (O(t^2)).
 * O(t^2) + O(t^2) = O(t^2).
 * Después entra en 2 for que recorren el tablero buscando si la posición es adyacente a 121 y no está en jugadas
 * ni tiene banderita. Los ciclos recorren el tablero, por lo que su complejidad en conjunto es O(t^2).
 * Veamos la complejidad de es adyacente121:
 *
 * Esta función depende de es121Horizontal y es 121Vertical. Ambas funciónes buscan posiciones jugadas continuas
 * que sean uno dos uno y para hacerlo tiene que recorrer jugadas 3 veces por lo tanto es
 * O(j) + O(j) + O(j) = O(j) = O(t^2).
 * Como en esAdyacente121 aparecen es121Horizontal y es 121Vertical evaluadas para cuatro posiciones
 * la complejidad de esAdyacente121 es: O(t^2) + O(t^2) + O(t^2) + O(t^2) = O(t^2).
 *
 * Resumiendo:
 * Hay un if de complejidad O(t^2) que contiene 2 ciclos for de complejidad O(t^2) que a su vez contienen un if de O(t^2).
 * En el peor de los casos se ejecuta el primer if, los dos ciclos anidados y se ejecuta t^2 veces el if interior.
 * Es decir: O(t^2) + O(t^2) * O(t^2) = O(t^2) + O(t^4) = O(t^4). */

bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    return hayPosicionSugerible(j, b, t, p);
}
