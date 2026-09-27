#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Usamos indexación 1-based
    vector<int> f(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }

    bool found = false;
    for (int i = 1; i <= n; ++i) {
        int a = i;
        int b = f[a];
        int c = f[b];
        int d = f[c];

        // Verificamos si forma un ciclo de longitud 3
        if (d == a) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}