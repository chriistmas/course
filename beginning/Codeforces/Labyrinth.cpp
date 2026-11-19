#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

struct State {
    int r, c;
};

int main() {
    // Fast I/O for 2000x2000 grid
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    int start_r, start_c;
    cin >> start_r >> start_c;
    // Convert to 0-based indexing
    start_r--; 
    start_c--;

    long long max_left, max_right;
    cin >> max_left >> max_right;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    const int INF = 1e9 + 7;
    // dist[i][j] stores the minimum left moves to reach (i, j)
    vector<vector<int>> dist(n, vector<int>(m, INF));
    deque<State> dq;

    dist[start_r][start_c] = 0;
    dq.push_front({start_r, start_c});

    // Directions: Up, Down, Right, Left
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!dq.empty()) {
        State curr = dq.front();
        dq.pop_front();

        int r = curr.r;
        int c = curr.c;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check grid boundaries and obstacles
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == '*') {
                continue;
            }

            // Moving left (i == 3) costs 1; other directions cost 0
            int weight = (i == 3) ? 1 : 0;

            if (dist[r][c] + weight < dist[nr][nc]) {
                dist[nr][nc] = dist[r][c] + weight;
                if (weight == 0) {
                    dq.push_front({nr, nc});
                } else {
                    dq.push_back({nr, nc});
                }
            }
        }
    }

    int reachable_cells = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == INF) continue;

            long long left_used = dist[i][j];
            long long right_used = left_used + (j - start_c);

            if (left_used <= max_left && right_used <= max_right) {
                reachable_cells++;
            }
        }
    }

    cout << reachable_cells << "\n";

    return 0;
}
