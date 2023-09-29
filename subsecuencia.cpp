#include <iostream>
#include <string>

using namespace std;

pair<bool, int> estaEnRango(char letra, int indice, string t){
    bool esta = false;
    int indiceNuevo = indice;
    for (int i = indice; i < t.size() && !esta; ++i) {
        if (t[i] == letra){
            esta = true;
            indiceNuevo = i;
        }
    }
    pair<bool, int> par(esta, indiceNuevo);
    return par;
}

bool subsecuencia(string s, string t) {
    int cont = 0;
    int indice = 0;
    for (int letra = 0; letra < s.size(); ++letra) {
        if (estaEnRango(s[letra], indice, t).first){
            indice = estaEnRango(s[letra], indice, t).second + 1;
        }
        else{
            cont += 1;
        }
    }
    return cont == 0;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s, t;
    cin >> s >> t;

    bool res = subsecuencia(s, t);
    cout << (res ? "true" : "false");
    return 0;
}

