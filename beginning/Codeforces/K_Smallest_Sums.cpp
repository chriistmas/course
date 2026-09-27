#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

vector<int> merge_two(const vector<int>& A, const vector<int>& B, int k) {
    //{suma, indice_en_A, indice_en_B}
    using Element = tuple<int, int, int>;
    priority_queue<Element, vector<Element>, greater<Element>> pq;

    for (int i = 0; i < k; ++i) {
        pq.emplace(A[i] + B[0], i, 0);
    }

    vector<int> result;
    result.reserve(k);

    for (int step = 0; step < k; ++step) {
        auto [sum, i, j] = pq.top();
        pq.pop();

        result.push_back(sum);

        if (j + 1 < k) {
            pq.emplace(A[i] + B[j + 1], i, j + 1);
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    while (cin >> k) {
        vector<int> current(k);
        for (int i = 0; i < k; ++i) {
            cin >> current[i];
        }
        sort(current.begin(), current.end());

        for (int row = 1; row < k; ++row) {
            vector<int> next_row(k);
            for (int i = 0; i < k; ++i) {
                cin >> next_row[i];
            }
            sort(next_row.begin(), next_row.end());

            current = merge_two(current, next_row, k);
        }

        for (int i = 0; i < k; ++i) {
            cout << current[i] << (i + 1 == k ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}