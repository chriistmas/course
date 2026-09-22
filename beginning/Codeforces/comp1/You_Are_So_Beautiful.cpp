#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<bool> is_first(n, false);
    vector<bool> is_last(n, false);

    map<int, int> first_pos;
    for (int i = 0; i < n; ++i) {
        if (first_pos.find(a[i]) == first_pos.end()) {
            first_pos[a[i]] = i;
            is_first[i] = true;
        }
    }

    map<int, int> last_pos;
    for (int i = n - 1; i >= 0; --i) {
        if (last_pos.find(a[i]) == last_pos.end()) {
            last_pos[a[i]] = i;
            is_last[i] = true;
        }
    }

    vector<int> cnt_last(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        cnt_last[i] = cnt_last[i + 1] + (is_last[i] ? 1 : 0);
    }

    long long total_subarrays = 0;
    for (int i = 0; i < n; ++i) {
        if (is_first[i]) {
            total_subarrays += cnt_last[i];
        }
    }

    cout << total_subarrays << "\n";
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