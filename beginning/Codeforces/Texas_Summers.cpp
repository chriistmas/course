#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Point {
    long long x, y;
};

long long dist_sq(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // 0 .. n-1: zonas con sombra
    // n: dormitorio (inicio)
    // n+1: clase (destino)
    int total_nodes = n + 2;
    vector<Point> pts(total_nodes);
    for (int i = 0; i < total_nodes; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    int start = n;
    int target = n + 1;

    vector<long long> dist(total_nodes, INF);
    vector<int> parent(total_nodes, -1);
    vector<bool> visited(total_nodes, false);

    dist[start] = 0;

    // Dijkstra O(V^2) sin heap, ideal para grafos completos densos
    for (int step = 0; step < total_nodes; ++step) {
        int u = -1;
        for (int i = 0; i < total_nodes; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (u == -1 || dist[u] == INF || u == target) break;
        visited[u] = true;

        for (int v = 0; v < total_nodes; ++v) {
            if (!visited[v]) {
                long long w = dist_sq(pts[u], pts[v]);
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    // Reconstruimos los indices de los puntos con sombra visitados
    vector<int> path;
    for (int cur = parent[target]; cur != start && cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    if (path.empty()) {
        cout << "-\n";
    } else {
        for (int idx : path) {
            cout << idx << "\n";
        }
    }

    return 0;
}