#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    string s;
    cin >> s;

    // Fast lookup for available letters
    vector<bool> available(26, false);
    for (int i = 0; i < k; ++i) {
        char ch;
        cin >> ch;
        available[ch - 'a'] = true;
    }

    long long total_substrings = 0;
    long long current_len = 0;

    for (int i = 0; i < n; ++i) {
        if (available[s[i] - 'a']) {
            current_len++;
        } else {
            total_substrings += (current_len * (current_len + 1)) / 2;
            current_len = 0; // Reset length for the next block
        }
    }
    
    // Add the final remaining block if it ends at the last character
    total_substrings += (current_len * (current_len + 1)) / 2;

    cout << total_substrings << "\n";

    return 0;
}
