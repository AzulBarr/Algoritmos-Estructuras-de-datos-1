#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int j) {
    string res(s);
    for (int i = 0; i < s.size(); ++i) {
        res[(i+j) % s.size()] = s[i];
    }
    return res;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;

    string res = rotar(s, j);
    cout << res;
    return 0;
}
