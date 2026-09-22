#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // La respuesta óptima siempre es la suma de los dos mayores menos los dos menores
    long long ans = (a[n - 1] + a[n - 2]) - (a[0] + a[1]);
    cout << ans << "\n";
}

int main() {
    // Optimización de E/S para CPH
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}