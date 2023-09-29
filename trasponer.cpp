#include <iostream>
#include <vector>

using namespace std;

void trasponer(vector<vector<int> > &m) {
    vector<vector<int>> m0 = m;
    int alto = m.size();
    int i = 0;
    while (i < alto){
        int j = 0;
        while (j < alto){
            m[j][i] = m0[i][j];
            j++;
        }
        i++;
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

    trasponer(m);

    cout << filas << " " << columnas << endl;
    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            cout << m[f][c] << " ";
        }
        cout << endl;
    }

    return 0;
}

