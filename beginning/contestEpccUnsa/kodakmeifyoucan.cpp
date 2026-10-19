#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Valor constante para representar el infinito en los cálculos de mínimo
const int INF = 1e9;

void resolver_circuito(int N, const vector<vector<int>>& D) {
    int K;
    cin >> K;
    
    vector<int> lugares(K);
    for (int i = 0; i < K; ++i) {
        cin >> lugares[i];
    }
    
    // Regla: El primero es la partida y el último es la meta
    int partida = lugares[0];
    int meta = lugares[K - 1];
    
    // Extraemos únicamente los lugares intermedios para permutarlos
    vector<int> intermedios;
    for (int i = 1; i < K - 1; ++i) {
        intermedios.push_back(lugares[i]);
    }
    
    // Es necesario ordenar el vector para que next_permutation genere todas las combinaciones
    sort(intermedios.begin(), intermedios.end());
    
    int tiempo_minimo = INF;
    
    // Evaluamos cada posible orden de los lugares intermedios
    do {
        int tiempo_actual = 0;
        int nodo_actual = partida;
        bool ruta_valida = true;
        
        // 1. Calculamos el tiempo viajando a través de los nodos intermedios
        for (int siguiente_nodo : intermedios) {
            int costo = D[nodo_actual][siguiente_nodo];
            
            if (costo == 0) { // 0 significa que el trayecto no está disponible
                ruta_valida = false;
                break;
            }
            tiempo_actual += costo;
            nodo_actual = siguiente_nodo;
        }
        
        // 2. Si la ruta sigue siendo válida, añadimos el tramo final hacia la meta
        if (ruta_valida) {
            int costo_final = D[nodo_actual][meta];
            if (costo_final == 0) {
                ruta_valida = false;
            } else {
                tiempo_actual += costo_final;
            }
        }
        
        // Si logramos completar todo el circuito, actualizamos el mínimo global
        if (ruta_valida) {
            tiempo_minimo = min(tiempo_minimo, tiempo_actual);
        }
        
    } while (next_permutation(intermedios.begin(), intermedios.end()));
    
    // Output: Si el tiempo mínimo cambió, lo imprimimos. Si no, significa que no hubo ruta válida (0)
    if (tiempo_minimo == INF) {
        cout << 0 << "\n";
    } else {
        cout << tiempo_minimo << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, C;
    if (!(cin >> N >> C)) return 0;
    
    // Matriz de adyacencia D de tamaño (N + 1) x (N + 1) indexada desde 1
    vector<vector<int>> D(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> D[i][j];
        }
    }
    
    // Procesamos cada circuito uno por uno de manera independiente
    for (int c = 0; c < C; ++c) {
        resolver_circuito(N, D);
    }
    
    return 0;
}
