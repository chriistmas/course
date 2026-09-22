#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

// Fusiona dos arreglos ordenados A y B extrayendo únicamente las k sumas mínimas
vector<int> merge_two(const vector<int>& A, const vector<int>& B, int k) {
    // Guarda: {suma, indice_en_A, indice_en_B}
    using Element = tuple<int, int, int>;
    priority_queue<Element, vector<Element>, greater<Element>> pq;

    // Inicializamos con A[i] + B[0] para todo i en [0, k - 1]
    for (int i = 0; i < k; ++i) {
        pq.emplace(A[i] + B[0], i, 0);
    }

    vector<int> result;
    result.reserve(k);

    // Extraemos exactamente las k menores sumas
    for (int step = 0; step < k; ++step) {
        auto [sum, i, j] = pq.top();
        pq.pop();

        result.push_back(sum);

        // Si existe un siguiente elemento en B para este A[i], lo agregamos a la cola
        if (j + 1 < k) {
            pq.emplace(A[i] + B[j + 1], i, j + 1);
        }
    }

    return result;
}

int main() {
    // Entrada/salida rápida indispensable para evitar TLE en jueces
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    while (cin >> k) {
        vector<int> current(k);
        for (int i = 0; i < k; ++i) {
            cin >> current[i];
        }
        sort(current.begin(), current.end());

        for (int row = 1; row < k; ++row) {
            vector<int> next_row(k);
            for (int i = 0; i < k; ++i) {
                cin >> next_row[i];
            }
            sort(next_row.begin(), next_row.end());

            // Combinamos acumulando solo las k mejores sumas
            current = merge_two(current, next_row, k);
        }

        // Imprimir el resultado de la fila final
        for (int i = 0; i < k; ++i) {
            cout << current[i] << (i + 1 == k ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}