#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    if (!(cin >> s >> t)) return 0;

    int n = s.size();
    int m = t.size();

    // left
    int L = 0;
    while (L < m && s[L] == t[L]) {
        L++;
    }

    // right
    int R = n - 1;
    int t_idx = m - 1;
    while (t_idx >= 0 && s[R] == t[t_idx]) {
        R--;
        t_idx--;
    }

    // R <= k <= L
    if (R > L) {
        cout << 0 << "\n";
    } else {
        cout << (L - R + 1) << "\n";
        for (int k = R; k <= L; ++k) {
            cout << k + 1 << (k == L ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}