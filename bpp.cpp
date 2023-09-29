#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int maximo(vector<int>& items){
    int max = items[0];
    int size = items.size();
    for (int i = 1; i < size; ++i) {
        if (items[i] > max){
            max = items[i];
        }
    }
    return max;
}

void cantidad(vector<int>& items, vector<int>& v){
    int size = items.size();
    for (int i = 0; i < size; ++i) {
        v[items[i]]++;
    }
}

void sumaAcumulativa(vector<int>& v){
    int size = v.size();
    for (int i = 1; i < size; i++) {
        v[i] += v[i - 1];
    }
}

vector<int> ordenamiento(vector<int>& items, vector<int>& v){
    vector<int> ord(items.size(),0);
    int size = items.size();
    for (int i = size - 1; i >= 0; i--) {
        ord[abs(size - v[items[i]])] = items[i];
        v[items[i]]--;
    }
    return ord;
}

void ordenar(vector<int> &items){
    int valorMax = maximo(items);
    vector<int> v(valorMax+1, 0);
    cantidad(items, v);
    sumaAcumulativa(v);
    items = ordenamiento(items, v);
}


int bestFit(int W, vector<int> &items){
    multiset<int> restos;
    for(int i=0; i<(int)items.size(); ++i){
        restos.insert(W);
    }
    int res = 0;
    for(int i=0; i<(int)items.size(); ++i){
        multiset<int>::iterator it = restos.lower_bound(items[i]);
        int restoAct = *it;
        if(restoAct==W){
            res++;
        }
        restoAct -= items[i];
        restos.erase(it);
        restos.insert(restoAct);
    }
    return res;
}

int main(){
    int N, W, aux;

    //Se levantan los items y la capacidad del contenedor
    cin >> N >> W;
    vector<int> items;
    for(int i=0; i<N; ++i){
        cin >> aux;
        items.push_back(aux);
    }
    //Se corre best-fit
    int cant1 = bestFit(W, items);
    cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

    //Se ordenan los items
    ordenar(items);
    //Se corre best-fit-decreasing
    int cant2 = bestFit(W, items);
    cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

    return 0;
}

