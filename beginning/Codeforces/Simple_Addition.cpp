#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sumar_grandes(string num1, string num2) {
    string resultado = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int llevo = 0;

    while (i >= 0 || j >= 0 || llevo) {
        int suma = llevo;
        
        if (i >= 0) {
            suma += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            suma += num2[j] - '0';
            j--;
        }
        
        llevo = suma / 10;
        resultado += (suma % 10) + '0';
    }

    reverse(resultado.begin(), resultado.end());
    return resultado;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n1, n2;
    if (cin >> n1 >> n2) {
        cout << sumar_grandes(n1, n2) << "\n";
    }

    return 0;
}
