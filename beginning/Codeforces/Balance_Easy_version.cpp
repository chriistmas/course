#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    // Optimizacion de I/O para CPH
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;

    set<long long> s;
    s.insert(0); // El conjunto inicialmente contiene 0

    // Guarda el proximo candidato de k-mex a revisar para cada k
    map<long long, long long> last_ans;

    while (q--) {
        char type;
        long long x;
        cin >> type >> x;

        if (type == '+') {
            s.insert(x);
        } else if (type == '?') {
            long long k = x;
            
            // Si nunca hemos consultado k, empezamos en k
            if (last_ans.find(k) == last_ans.end()) {
                last_ans[k] = k;
            }

            long long cur = last_ans[k];
            // Avanzamos en saltos de k mientras el multiplo exista en el conjunto
            while (s.count(cur)) {
                cur += k;
            }

            last_ans[k] = cur;
            cout << cur << "\n";
        }
    }

    return 0;
}