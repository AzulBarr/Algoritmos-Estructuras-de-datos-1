#include <vector>
#include <iostream>

using namespace std;

int indiceMinSubsec(vector<int> v, int l, int r){
    int i = l-1;
    int res = l;
    while (i < r){
        i++;
        if (v[i] < v[res]){
            res = i;
        }
    }
    return res;
}

void ordenar1(vector<int>& v){
    int i = 0;
    while (i < v.size()){
        int minimoIndice = indiceMinSubsec(v, i, v.size()-1);
        int a = v[minimoIndice];
        v[minimoIndice] = v[i];
        v[i] = a;
        i++;
    }
}

int main() {
    /* No hace falta modificar el main */
    
    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Hago el ordenamiento
    ordenar1(v);
    
    // Imprimo el vector resultado
    i = 0;
    while (i < v.size()){
        cout << v[i] << " ";
        i++;
    }
    
    return 0;
}
