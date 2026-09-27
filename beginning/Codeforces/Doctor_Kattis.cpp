#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <tuple>

using namespace std;

// Estructura para registrar los datos internos de cada gato
struct Cat {
    string name;
    int infectionLevel;
    int arrivalTime;
    bool inClinic;
};

int main() {
    // E/S rapida obligatoria para 10^6 operaciones
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Cat> cats;
    cats.reserve(200005);
    unordered_map<string, int> name_to_id;
    name_to_id.reserve(200005);

    // Set ordenado: {-infectionLevel, arrivalTime, catID}
    // Al usar -infectionLevel, el mayor nivel de infeccion queda al inicio.
    // Al desempatar con arrivalTime ascendente, el que llego antes queda al inicio.
    set<tuple<int, int, int>> pq;

    int arrival_counter = 0;

    for (int step = 0; step < N; ++step) {
        int type;
        cin >> type;

        if (type == 0) {
            string name;
            int level;
            cin >> name >> level;

            int id = cats.size();
            cats.push_back({name, level, arrival_counter, true});
            name_to_id[name] = id;

            pq.insert({-level, arrival_counter, id});
            arrival_counter++;
        } 
        else if (type == 1) {
            string name;
            int inc;
            cin >> name >> inc;

            int id = name_to_id[name];
            // Removemos el estado viejo del set
            pq.erase({-cats[id].infectionLevel, cats[id].arrivalTime, id});

            // Actualizamos la infeccion
            cats[id].infectionLevel += inc;

            // Reinsertamos con la nueva prioridad
            pq.insert({-cats[id].infectionLevel, cats[id].arrivalTime, id});
        } 
        else if (type == 2) {
            string name;
            cin >> name;

            int id = name_to_id[name];
            if (cats[id].inClinic) {
                pq.erase({-cats[id].infectionLevel, cats[id].arrivalTime, id});
                cats[id].inClinic = false;
            }
        } 
        else if (type == 3) {
            if (pq.empty()) {
                cout << "The clinic is empty\n";
            } else {
                auto [neg_level, arr_time, id] = *pq.begin();
                cout << cats[id].name << "\n";
            }
        }
    }

    return 0;
}