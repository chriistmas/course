#include <iostream>
#include <string>
#include <algorithm> // Aunque ya no uses next_permutation, puedes dejarlo si cambias el nombre

using namespace std;

// Le cambiamos el nombre para que no choque con std::generate
void backtrack(int n, int h, string current_str) {
    if (current_str.length() == n) {
        if (h == 0) {
            cout << current_str << "\n";
        }
        return;
    }

    if (h > (n - current_str.length())) return;

    // Opción 1: Intentar poner un '0'
    backtrack(n, h, current_str + '0');

    // Opción 2: Intentar poner un '1'
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

    // Llamamos a la función con el nuevo nombre
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
