#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool is_win(int x, int y) {
    if (x == 21 && y <= 19) return true;
    if (x >= 22 && x <= 29 && x - y == 2) return true;
    if (x == 30 && (y == 28 || y == 29)) return true;
    return false;
}

bool is_in_progress(int a, int b) {
    if (a <= 20 && b <= 20) return true;
    if (a <= 29 && b <= 29 && max(a, b) >= 20 && abs(a - b) <= 1) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (cin >> s) {
        int dash = s.find('-');
        int a = stoi(s.substr(0, dash));
        int b = stoi(s.substr(dash + 1));

        if (is_win(a, b)) {
            cout << "A\n";
        } else if (is_win(b, a)) {
            cout << "B\n";
        } else if (is_in_progress(a, b)) {
            cout << "?\n";
        } else {
            cout << "!\n";
        }
    }

    return 0;
}