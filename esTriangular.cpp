#include <iostream>
#include <vector>

using namespace std;

bool esTriangularInferior(vector<vector<int> > m){
    bool res = true;
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m.size(); ++j) {
            if (i < j){
                if (m[i][j] != 0)
                    res = false;
            }
        }
    }
    return res;
}

bool esTriangularSuperior(vector<vector<int> > m){
    bool res = true;
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m.size(); ++j) {
            if (j < i){
                if (m[i][j] != 0)
                    res = false;
            }
        }
    }
    return res;
}

bool esTriangular(const vector<vector<int> > &m){
    if (esTriangularInferior(m) || esTriangularSuperior(m)){
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    int n; // Cantidad de filas y columnas de la matriz
    cin >> n;
    int x;
    int filas = n, columnas = n;
    vector<vector<int> > m(filas, vector<int>(columnas, 0)); // En m leo la matriz

    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            cin >> x;
            m[f][c] = x;
        }
    }

    bool res = esTriangular(m);
    cout << (res ? "true" : "false");
    return 0;
}
