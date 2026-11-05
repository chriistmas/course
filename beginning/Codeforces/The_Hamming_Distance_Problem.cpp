#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void backtrack(int n, int h, string current_str) {
    if (current_str.length() == n) {
        if (h == 0) {
            cout << current_str << "\n";
        }
        return;
    }

    if (h > (n - current_str.length())) return;

    // pongo mi '0'
    backtrack(n, h, current_str + '0');

    // pongo mi '1'
    if (h > 0) {
        backtrack(n, h - 1, current_str + '1');
    }
}

void solve(bool is_first_dataset) {
    int n, h;
    if (!(cin >> n >> h)) return;

    if (!is_first_dataset) {
        cout << "\n";
    }

    backtrack(n, h, "");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        for (int i = 0; i < t; ++i) {
            solve(i == 0);
        }
    }

    return 0;
}
