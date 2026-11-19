#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    if (!(cin >> n >> t)) return 0;

    string s;
    cin >> s;

    // Simulate t seconds
    while (t--) {
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'B' && s[i + 1] == 'G') {
                swap(s[i], s[i + 1]);
                // Skip the next index so this boy doesn't move again this second
                i++; 
            }
        }
    }

    cout << s << "\n";

    return 0;
}
