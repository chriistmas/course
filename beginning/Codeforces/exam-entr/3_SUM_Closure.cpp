#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> pos, neg;
    int zeros = 0;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (x > 0) pos.push_back(x);
        else if (x < 0) neg.push_back(x);
        else zeros++;
    }

    // Si hay 3 o más positivos o 3 o más negativos, es imposible
    if (pos.size() >= 3 || neg.size() >= 3) {
        cout << "NO\n";
        return;
    }

    // Construimos el arreglo reducido con a lo más 2 ceros
    vector<long long> b;
    for (long long x : pos) b.push_back(x);
    for (long long x : neg) b.push_back(x);
    for (int i = 0; i < min(zeros, 2); ++i) b.push_back(0);

    int m = b.size();

    // Verificamos todas las ternas de índices distintos en el arreglo reducido
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                long long sum = b[i] + b[j] + b[k];
                bool exists = false;
                for (int l = 0; l < m; ++l) {
                    if (b[l] == sum) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
}

int main() {
    // Optimización de I/O para CPH
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}