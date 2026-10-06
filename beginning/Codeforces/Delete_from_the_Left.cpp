#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    while (cin >> s >> t) {
        int i = (int)s.size() - 1;
        int j = (int)t.size() - 1;
        int common_suffix_len = 0;

        while (i >= 0 && j >= 0 && s[i] == t[j]) {
            common_suffix_len++;
            i--;
            j--;
        }

        int ans = (int)s.size() + (int)t.size() - 2 * common_suffix_len;
        cout << ans << "\n";
    }

    return 0;
}