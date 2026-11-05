#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    // Indexado a 1 para mayor claridad (a[1 ... n])
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // dp[i][0]: el siguiente turno le toca a tu amigo (acabas de jugar tu)
    // dp[i][1]: el siguiente turno te toca a ti (acaba de jugar tu amigo)
    vector<vector<int>> dp(n + 1, vector<int>(2, INF));

    // Casos base (el primer turno es de tu amigo)
    dp[1][1] = a[1];
    if (n >= 2) {
        dp[2][1] = a[1] + a[2];
        dp[2][0] = dp[1][1];
    }

    for (int i = 3; i <= n; ++i) {
        // Tu turno (derrotas 1 o 2 jefes sin costo)
        dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);

        // Turno de tu amigo (derrota 1 o 2 jefes pagando a[i] o a[i-1]+a[i])
        dp[i][1] = min(dp[i - 1][0] + a[i], dp[i - 2][0] + a[i - 1] + a[i]);
    }

    // La respuesta minima considerando si el ultimo turno lo jugaste tu o tu amigo
    cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}