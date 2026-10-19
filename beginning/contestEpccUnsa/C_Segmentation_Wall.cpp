#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimización extrema de la entrada y salida estándar de C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Variables para determinar el contenedor mínimo (Bounding Box)
    long long min_x = 2e9, min_y = 2e9;
    long long max_x = -2e9, max_y = -2e9;
    long long suma_areas = 0;

    // Vector para almacenar las 4 esquinas de cada uno de los N ladrillos
    // Total de elementos: 4 * N
    vector<pair<int, int>> esquinas;
    esquinas.reserve(4 * n);

    for (int i = 0; i < n; ++i) {
        long long x, y, w, h;
        cin >> x >> y >> w >> h;

        long long x2 = x + w;
        long long y2 = y + h;

        // Actualizamos las dimensiones del contenedor exterior
        min_x = min(min_x, x);
        min_y = min(min_y, y);
        max_x = max(max_x, x2);
        max_y = max(max_y, y2);

        // Sumamos el área del ladrillo actual
        suma_areas += (w * h);

        // Insertamos las 4 esquinas del ladrillo
        esquinas.push_back({x, y});
        esquinas.push_back({x, y2});
        esquinas.push_back({x2, y});
        esquinas.push_back({x2, y2});
    }

    // Primera validación obligatoria: ¿El área total coincide?
    long long area_contenedor = (max_x - min_x) * (max_y - min_y);
    if (suma_areas != area_contenedor) {
        cout << "no\n";
        return 0;
    }

    // Ordenamos todas las esquinas para agrupar las idénticas consecutivamente
    sort(esquinas.begin(), esquinas.end());

    // Buscaremos cuáles puntos tienen una frecuencia impar
    vector<pair<int, int>> esquinas_impares;
    
    int i = 0;
    int total_puntos = esquinas.size();
    while (i < total_puntos) {
        int j = i;
        // Contamos cuántas veces se repite la esquina actual
        while (j < total_puntos && esquinas[j] == esquinas[i]) {
            j++;
        }
        
        int frecuencia = j - i;
        // Si la frecuencia es impar, la guardamos
        if (frecuencia % 2 != 0) {
            esquinas_impares.push_back(esquinas[i]);
        }
        i = j; // Avanzamos al siguiente grupo de puntos únicos
    }

    // Segunda validación obligatoria: 
    // Debe haber exactamente 4 esquinas con conteo impar
    if (esquinas_impares.size() != 4) {
        cout << "no\n";
        return 0;
    }

    // Verificamos que esas 4 esquinas sean exactamente las del contenedor mínimo
    // Al estar el vector ordenado, el orden por defecto es el correcto para comparar
    if (esquinas_impares[0] == make_pair((int)min_x, (int)min_y) &&
        esquinas_impares[1] == make_pair((int)min_x, (int)max_y) &&
        esquinas_impares[2] == make_pair((int)max_x, (int)min_y) &&
        esquinas_impares[3] == make_pair((int)max_x, (int)max_y)) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    return 0;
}
