#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimización de la entrada y salida estándar para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    // Vector booleano para marcar rápidamente qué nodos pertenecen a Alioth inicialmente
    vector<bool> es_alioth(n + 1, false);
    for (int i = 0; i < k; ++i) {
        int u;
        cin >> u;
        es_alioth[u] = true;
    }

    // Leemos los túneles originales y verificamos si alguno conecta a Alioth con el refugio (n)
    bool alioth_adyacente_al_refugio = false;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Si el túnel conecta el nodo 'n' con un nodo invadido por Alioth
        if ((u == n && es_alioth[v]) || (v == n && es_alioth[u])) {
            alioth_adyacente_al_refugio = true;
        }
    }

    // Si Alioth ya está a un paso del refugio en el mapa inicial, no hay forma de salvarlos
    if (alioth_adyacente_al_refugio) {
        cout << -1 << "\n";
        return 0;
    }

    // Total máximo de túneles en un grafo completo de N nodos
    long long max_total_posible = (1LL * n * (n - 1)) / 2;

    // Restamos las 'k' conexiones prohibidas entre los 'k' nodos de Alioth y el nodo 'n'
    long long max_tuneles_permitidos = max_total_posible - k;

    // Los túneles adicionales que Deadpool puede construir
    long long adicionales = max_tuneles_permitidos - m;

    cout << adicionales << "\n";

    return 0;
}
