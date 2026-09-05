#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // pref_min[i] guardará el mínimo en a[0 ... i]
    vector<int> pref_min(n);
    pref_min[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref_min[i] = min(pref_min[i - 1], a[i]);
    }

    // suff_max[i] guardará el máximo en a[i ... n-1]
    vector<int> suff_max(n);
    suff_max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suff_max[i] = max(suff_max[i + 1], a[i]);
    }

    // Un elemento puede quedar solo si es el mínimo de su prefijo
    // o el máximo de su sufijo
    string ans = "";
    for (int i = 0; i < n; ++i) {
        if (a[i] == pref_min[i] || a[i] == suff_max[i]) {
            ans += '1';
        } else {
            ans += '0';
        }
    }

    cout << ans << "\n";
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