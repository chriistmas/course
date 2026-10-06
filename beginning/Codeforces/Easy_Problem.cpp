#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    // La cantidad de pares ordenados (a, b) positivos es siempre n - 1
    cout << n - 1 << "\n";
}

int main() {
    // Optimización de Entrada/Salida estándar para programación competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
