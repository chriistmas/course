#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> masks(n, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int m = 0;
        for (char c : s) {
            m ^= (1 << (c - 'a'));
        }
        masks[i] = m;
    }

    // Usamos unordered_map con reserva para evitar colisiones excesivas
    unordered_map<int, int> freq;
    freq.reserve(n * 2);

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int m = masks[i];

        // Caso 1: Mascara identica (xor = 0)
        auto it = freq.find(m);
        if (it != freq.end()) {
            ans += it->second;
        }

        // Caso 2: Mascara difiere en exactamente 1 bit (xor = 2^b)
        for (int b = 0; b < 26; ++b) {
            int target = m ^ (1 << b);
            auto it2 = freq.find(target);
            if (it2 != freq.end()) {
                ans += it2->second;
            }
        }

        // Registrar la mascara actual
        freq[m]++;
    }

    cout << ans << "\n";

    return 0;
}