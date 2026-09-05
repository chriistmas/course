#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    // Buscando de derecha a izquierda obtenemos el pico del ejemplo (3 5 6)
    for (int j = n - 2; j >= 1; --j) {
        if (p[j - 1] < p[j] && p[j] > p[j + 1]) {
            cout << "YES\n";
            // 1-based indexing
            cout << j << " " << j + 1 << " " << j + 2 << "\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}