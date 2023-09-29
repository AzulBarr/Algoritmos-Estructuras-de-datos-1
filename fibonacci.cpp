#include <iostream>

using namespace std;

// Funcion de fibonacci que calcula n-esimo termino


int fibonacci(int n){
    int secuencia;
    for (int i = 0; i == n ; ++i) {
        if (n == 0)
            secuencia = 0;
        if (n == 1)
            secuencia = 1;

        secuencia = secuencia + i;

    }
    return secuencia;
}
int main() 
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;    
    return 0;
}