#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        const double INF = 1e18;
        vector<vector<double>> dist(n, vector<double>(n, INF));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0.0;
        }

        auto get_euclid = [&](int i, int j) {
            return hypot(x[i] - x[j], y[i] - y[j]);
        };

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            double d = get_euclid(u, v);
            dist[u][v] = min(dist[u][v], d);
            dist[v][u] = min(dist[v][u], d);
        }

        // Initial Floyd-Warshall in O(n^3)
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        double initial_total = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                initial_total += dist[i][j];
            }
        }

        double best_total = initial_total;
        int best_u = -1, best_v = -1;

        // Try adding every candidate road (u, v) in lexicographical order
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                double w = get_euclid(u, v);
                double current_total = 0.0;

                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        double via_uv = dist[i][u] + w + dist[v][j];
                        double via_vu = dist[i][v] + w + dist[u][j];
                        current_total += min({dist[i][j], via_uv, via_vu});
                    }
                }

                // Strictly better by more than floating-point noise
                if (current_total + 1e-9 < best_total) {
                    best_total = current_total;
                    best_u = u;
                    best_v = v;
                }
            }
        }

        cout << fixed << setprecision(10);
        if (best_u == -1) {
            cout << "no addition reduces " << initial_total << "\n";
        } else {
            cout << "adding " << best_u << " " << best_v
                 << " reduces " << initial_total << " to " << best_total << "\n";
        }
    }

    return 0;
}
