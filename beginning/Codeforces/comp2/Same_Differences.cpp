#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, long long> freq;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        // a_i - i (usando indexacion 0-based o 1-based da el mismo resultado)
        freq[a - i]++;
    }

    long long ans = 0;
    for (auto const& [val, count] : freq) {
        ans += count * (count - 1) / 2;
    }

    cout << ans << "\n";
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