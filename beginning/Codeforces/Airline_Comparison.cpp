#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    for (int tc = 0; tc < t; tc++) {
        // Print a blank line between consecutive test cases
        if (tc > 0) {
            cout << "\n";
        }

        // 26 uppercase letters ('A' to 'Z')
        vector<vector<bool>> reach1(26, vector<bool>(26, false));
        vector<vector<bool>> reach2(26, vector<bool>(26, false));

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char u, v;
            cin >> u >> v;
            reach1[u - 'A'][v - 'A'] = true;
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            char u, v;
            cin >> u >> v;
            reach2[u - 'A'][v - 'A'] = true;
        }

        // Floyd-Warshall to compute transitive closure for both airlines
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (reach1[i][k] && reach1[k][j]) {
                        reach1[i][j] = true;
                    }
                    if (reach2[i][k] && reach2[k][j]) {
                        reach2[i][j] = true;
                    }
                }
            }
        }

        // Check if both airlines offer the exact same reachable city pairs
        bool equivalent = true;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) continue;
                if (reach1[i][j] != reach2[i][j]) {
                    equivalent = false;
                    break;
                }
            }
            if (!equivalent) break;
        }

        cout << (equivalent ? "YES" : "NO") << "\n";
    }

    return 0;
}
