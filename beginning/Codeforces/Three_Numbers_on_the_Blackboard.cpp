#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    vector<long long> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());

    long long a = v[0], b = v[1], c = v[2];

    if (a == 0 && b == 0) {
        cout << 0 << "\n";
        return;
    }

    if (c > a + b) {
        cout << min(c - a, b) << "\n";
    } else {
        cout << c - a << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}