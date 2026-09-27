#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<pair<string, int>> rounds(n);
    map<string, int> final_score;

    for (int i = 0; i < n; ++i) {
        cin >> rounds[i].first >> rounds[i].second;
        final_score[rounds[i].first] += rounds[i].second;
    }

    // Encontrar la maxima puntuacion obtenida al final del juego
    int max_points = -1e9;
    for (auto const& [name, score] : final_score) {
        max_points = max(max_points, score);
    }

    // Segunda pasada: encontrar quien de los que alcanzan max_points
    // llego a tener >= max_points primero
    map<string, int> current_score;
    for (int i = 0; i < n; ++i) {
        string name = rounds[i].first;
        int points = rounds[i].second;
        current_score[name] += points;

        if (final_score[name] == max_points && current_score[name] >= max_points) {
            cout << name << "\n";
            break;
        }
    }

    return 0;
}