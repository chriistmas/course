#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    if (!(cin >> s >> t)) return 0;

    int x1 = s[0] - 'a', y1 = s[1] - '1';
    int x2 = t[0] - 'a', y2 = t[1] - '1';

    int moves = max(abs(x2 - x1), abs(y2 - y1));
    cout << moves << "\n";

    while (x1 != x2 || y1 != y2) {
        string step = "";
        if (x1 < x2) {
            step += 'R';
            x1++;
        } else if (x1 > x2) {
            step += 'L';
            x1--;
        }

        if (y1 < y2) {
            step += 'U';
            y1++;
        } else if (y1 > y2) {
            step += 'D';
            y1--;
        }

        cout << step << "\n";
    }

    return 0;
}