#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v;
    double weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

void solve(int case_num) {
    int n;
    double r;
    if (!(cin >> n >> r)) return;

    vector<pair<double, double>> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }

    // Generar todas las aristas posibles entre pares de ciudades
    vector<Edge> edges;
    edges.reserve(n * (n - 1) / 2);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dx = cities[i].first - cities[j].first;
            double dy = cities[i].second - cities[j].second;
            double dist = hypot(dx, dy);
            edges.push_back({i, j, dist});
        }
    }

    // Ordenar aristas de menor a mayor distancia (Algoritmo de Kruskal)
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int states = 1;
    double roads_len = 0.0;
    double railroads_len = 0.0;
    int edges_used = 0;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            if (edge.weight <= r) {
                roads_len += edge.weight;
            } else {
                railroads_len += edge.weight;
                states++;
            }
            edges_used++;
            if (edges_used == n - 1) break;
        }
    }

    cout << "Case #" << case_num << ": " 
         << states << " " 
         << (long long)round(roads_len) << " " 
         << (long long)round(railroads_len) << "\n";
}

int main() {
    // Optimización de entrada/salida
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; ++i) {
            solve(i);
        }
    }

    return 0;
}